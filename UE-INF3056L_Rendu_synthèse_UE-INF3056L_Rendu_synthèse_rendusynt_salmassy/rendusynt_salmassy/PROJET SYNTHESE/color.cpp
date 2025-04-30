#include <cmath>
#include "color.h"

float Color::power( ) const
{
    // moy des comp
    return (r+g+b) / 3;
}

float Color::max( ) const
{
    // max entre r g b
    return std::max(r, std::max(g, std::max(b, float(0))));
}

Color Black( )
{
    // noir simple
    return Color(0, 0, 0);
}

Color White( )
{
    // blanc pur
    return Color(1, 1, 1);
}

Color Red( )
{
    // juste rouge
    return Color(1, 0, 0);
}

Color Green( )
{
    // juste vert
    return Color(0, 1, 0);
}

Color Blue( )
{
    // juste bleu
    return Color(0, 0, 1);
}

Color Yellow( )
{
    // rouge + vert
    return Color(1, 1, 0);
}

float srgb( const float x )
{
    // passage vers srgb
    if(x < 0.00031308f) return 12.92f * x;
    else return std::pow(1.055f * x, 1.0f / 2.4f) - 0.055f;
}

float linear( const float x )
{
    // passage vers lineaire
    if(x < 0.04045f) return x / 12.92f;
    else return std::pow((x + 0.055f) / 1.055f, 2.4f);
}

Color srgb( const Color& color, const float g )
{
    // version srgb couleur
    return Color(srgb(color.r), srgb(color.g), srgb(color.b), color.a);
}

Color linear( const Color& color, const float g )
{
    // version lineaire couleur
    return Color(linear(color.r), linear(color.g), linear(color.b), color.a);
}

Color operator+ ( const Color& a, const Color& b )
{
    // addition compo
    return Color(a.r + b.r, a.g + b.g, a.b + b.b, a.a + b.a);
}

Color operator- ( const Color& c )
{
    // inverse les compo
    return Color(-c.r, -c.g, -c.b, -c.a);
}

Color operator- ( const Color& a, const Color& b )
{
    // soustraction des deux
    return a + (-b);
}

Color operator* ( const Color& a, const Color& b )
{
    // produit par element
    return Color(a.r * b.r, a.g * b.g, a.b * b.b, a.a * b.a);
}

Color operator* ( const float k, const Color& c )
{
    // mult avec scalaire
    return Color(c.r * k, c.g * k, c.b * k, c.a * k);
}

Color operator* ( const Color& c, const float k )
{
    // ordre inverse meme chose
    return k * c;
}

Color operator/ ( const Color& a, const Color& b )
{
    // division composantes
    return Color(a.r / b.r, a.g / b.g, a.b / b.b, a.a / b.a);
}

Color operator/ ( const float k, const Color& c )
{
    // scalaire sur couleur
    return Color(k / c.r, k / c.g, k / c.b, k / c.a);
}

Color operator/ ( const Color& c, const float k )
{
    // couleur sur scalaire
    float kk = 1 / k;
    return kk * c;
}
