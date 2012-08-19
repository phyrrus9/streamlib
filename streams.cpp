/*
 Stream library copyright © 2012 phyrrus9 (Ethan Laur) <phyrrus9@gmail.com>
 This library is an attempt at making some of those nasty conversions a lot
 easier on the programmer by just linking to the library and using the .h
 file to grab the functions and classes. This library is open source, so it
 can be used in any way you wish, with some exceptions as listed below.
 This library must be distributed with the original copyright block on all
 files intact, to give proper credit to the people who have put work into
 this library as they deserve it. This library must also be distributed as
 open source under the same lisencing terms listed in this copyright block.
 This library is distributed in the hope that it will be useful, there is
 no warranty provided with this software but it would be appreciated if any
 bugs could be reported to the original author (phyrrus9) contact details
 on first line of this block. If you contribute to this project, feel free
 to add your name in the credits below and please please notify the author
 of your changes so we can add them to the oficial library with permission
 from you, as you deserve credit for your work.
 The following developers have contributed to this library:
 Ethan Laur (phyrrus9) <phyrrus9@gmail.com> 2012
 If you feel this library infringes on any of your personal copyrights feel
 free to contact the authors so we can either ask for your permission to
 use the copyrighted material or remove the material from the library.
 In this library I have provided a simple versioning system, the c++ macro
 streamlib_version is an integer that tells what build number the library
 is. PLEASE ensure your program is compiling with the correct version .a
 file, this can be checked by testing streamlib_version with the const int
 in the library file GLOBAL_STREAMLIB_VERSION. If they do not match, do NOT
 compile your program as it could be harmful.
 Any comments, questions, or concerns would be appreciated so please do not
 hesitate to contact any developer and talk to us, that is what we are here
 for. Thank you and happy programming with streamlib.
 */
#include "streams.h"
const int GLOBAL_STREAMLIB_VERSION = 1;
void strcat(std::string dest, const char * source)
{
    dest += source;
}
void strcat(char * dest, std::string source)
{
    strcat(dest, source.c_str());
}
const char * itocc(int input)
{
    std::ostringstream t;
    t << input;
    return t.str().c_str();
}
namespace temperature
{
    //temp conversion functions
    int ctof(int c)
    {
        return (c * (9/5)) + 32;
    }   
    int ftoc(int f)
    {
        return (f-32)*(5/9);
    }
    int ctok(int c)
    {
        return c + 273;
    }
    int ktoc(int k)
    {
        return k - 273;
    }
    int ftok(int f)
    {
        return temperature::ctok(temperature::ftoc(f));
    }
    int ktof(int k)
    {
        return temperature::ctof(temperature::ktoc(k));
    }
}

namespace temperature
{
    //classes
    void kelvin::operator=(int i)
    {
        temperature = i;
    }
    void kelvin::operator=(kelvin k)
    {
        temperature = k.get();
    }
    void kelvin::operator+=(int i)
    {
        temperature += i;
    }
    void kelvin::operator+=(kelvin k)
    {
        temperature += k.get();
    }
    kelvin kelvin::operator+(kelvin k)
    {
        kelvin kout;
        kout = temperature + k.get();
        return kout;
    }
    celsius kelvin::tocelsius(void)
    {
        celsius c;
        c = temperature::ktoc(temperature);
        return c;
    }
    farenhiet kelvin::tofarenhiet(void)
    {
        farenhiet f;
        f = temperature::ktof(temperature);
        return f;
    }
    int kelvin::get(void)
    {
        return temperature;
    }
    
    
    
    void celsius::operator=(int i)
    {
        temperature = i;
    }
    void celsius::operator=(celsius c)
    {
        temperature = c.get();
    }
    void celsius::operator+=(int i)
    {
        temperature += i;
    }
    void celsius::operator+=(celsius c)
    {
        temperature += c.get();
    }
    celsius celsius::operator+(celsius c)
    {
        celsius cout;
        cout = temperature +c.get();
        return cout;
    }
    kelvin celsius::tokelvin(void)
    {
        kelvin k;
        k = temperature::ctok(temperature);
        return k;
    }
    farenhiet celsius::tofarenhiet(void)
    {
        farenhiet f;
        f = temperature::ctof(temperature);
        return f;
    }
    int celsius::get(void)
    {
        return temperature;
    }
    
    
    void farenhiet::operator=(int i)
    {
        temperature = i;
    }
    void farenhiet::operator=(farenhiet f)
    {
        temperature = f.temperature;
    }
    void farenhiet::operator+=(int i)
    {
        temperature += i;
    }
    void farenhiet::operator+=(farenhiet f)
    {
        temperature += f.temperature;
    }
    farenhiet farenhiet::operator+(farenhiet f)
    {
        farenhiet fout;
        fout = temperature + f.get();
        return fout;
    }
    celsius farenhiet::tocelsius(void)
    {
        celsius c;
        c = temperature::ftoc(temperature);
        return c;
    }
    kelvin farenhiet::tokelvin(void)
    {
        kelvin k;
        k = temperature::ftok(temperature);
        return k;
    }
    int farenhiet::get(void)
    {
        return temperature;
    }
}