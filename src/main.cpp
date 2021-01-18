#include "../libKIni/KIni.h"
#include <iostream>
#include <cstdio>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: cog_magic.exe \"path/to/the/level.lv2\"\n";
        return 0;
    }

    KIniRoot* my_root = new KIniRoot(nullptr);
    bool out = parseKIni(my_root, argv[1]);
    if (!out)
    {
        std::cout << "File doesn't exist\n";
        return 0;
    }

    KIniElement* cogs = my_root->queryElementByName("GOLDENCOG");
    if (cogs == nullptr)
    {
        std::cout << "No cogs in this level\n";
        return 0;
    }
    ListMember<KIniInstance>* curr_cog = cogs->getMemberAtIndex(0);

    KIniElement* ty = my_root->queryElementByName("TY");
    if (ty == nullptr)
    {
        std::cout << "This level does not contain Ty\n";
        return 0;
    }

    std::cout << "Ty's Spawn: " + ty->getInstanceList()->getCurrentContained()->queryPropertyByName("pos")->getPropertyValue() + "\nThe cogs in this level have the following positions:\n";
    while (curr_cog != nullptr)
    {
        if (curr_cog->getCurrentContained()->queryPropertyByName("pos") != nullptr)
        {
            std::cout << curr_cog->getCurrentContained()->queryPropertyByName("pos")->toString();
        }
        curr_cog = curr_cog->getNextListMember();
    }

    delete my_root;

    return 0;
}
