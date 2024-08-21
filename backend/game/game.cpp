class Menu
{
public:
    virtual void render();
    virtual void update();
    virtual void handleInput();
};

class MainMenu : public Menu
{
    public:
        void render() override
        {
            // Render main menu
        }
        void update() override
        {
            // Update main menu
        }
        void handleInput() override
        {
            // Handle input for main menu

        }
};
