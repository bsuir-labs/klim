#include "UIController.h"
#include <locale>
#include <codecvt>

UIController::UIController()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    std::locale::global(locale("ru_RU.utf8")); // not sure if it is necessary
}

UIController::UIController(DataManager* dm, Authorization* auth):UIController()
{
    m_dm = dm;
    m_auth = auth;
}


UIController::~UIController()
{
}

void UIController::render()
{
    //wprintf(L"%s", layout->render().c_str());
    //_putws(layout->render().c_str());
    layout->run();
    //std::wstring res = layout->render();
    //std::wcout << res;
}

void UIController::interact()
{
    // nothing!
    //layout->interact();
}

void UIController::clr_scr(char fill)
{
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void UIController::quit(int exitcode)
{
    exit(exitcode);
}

void UIController::setLayout(Layout* l)
{
    m_lstack.push(l);
    layout = l;
    layout->setMaster(this);
}

void UIController::pop_ui()
{
    if (m_lstack.size() == 1) return;

    delete m_lstack.top();
    m_lstack.pop();
    layout = m_lstack.top();
    layout->setMaster(this);
}