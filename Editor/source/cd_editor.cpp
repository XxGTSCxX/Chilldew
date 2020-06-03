#include "cd_editor.h"

cde::app* cde::create_app()
{
    return new cd::editor{};
}

void cde::destroy_app(cde::app* game)
{
    delete game;
}

namespace chilldew
{

    editor::editor()
    {
        stop();
    }

    bool editor::is_editor() const
    {
        return true;
    }

    void editor::setup()
    {
        cde::debug::get()->LogWarning("Press [Enter] to Quit the app");
        std::cin.get();
        quit();
    }

}
