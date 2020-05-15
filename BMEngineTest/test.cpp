#include "pch.h"
#include "BMEngine.h"
#include "Movement.h"

using namespace bme;

TEST(TestCase, Test) 
{
    class TestScene : public Scene
    {
    public:
        TestScene(Context &context)
            : Scene(context)
        {
            p1 = new PointObject2D(context);
            p1->AddComponent<Movement>();
            AddGameObject(p1);
        }

    private:
        PointObject2D *p1;
    };

    Engine engine(800, 600, "Test", sf::Color::Black);
    engine.AddScene(new TestScene(engine.GetContext()));
    engine.Run();

    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}