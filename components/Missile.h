#include "raylib.h"
#include "Ship.h"

class Missile
{
    private:
        int Size=3;
        bool flag=0;
        Color Tone = GREEN;

        Vector2 Pos;
        Vector2 Dir;

    public:
        Missile(Vector2 Origin)
        {
            Pos = Origin;
            Dir={(GetMousePosition().x)-Pos.x,(GetMousePosition().y-Pos.y)};
        }
        void TrackPos()
        {
            Pos={(Pos.x+(Dir.x)/75),(Pos.y+(Dir.y)/75)};
            DrawCircle(Pos.x,Pos.y,Size,Tone);
        }

        Vector2 GetPos()
        {
            return(Pos);
        }
};