#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items)
{
}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items))
{
}

auto isFresh = [](int &quality) { (quality < 50) ? quality++ : quality; };

void agedFunc(int &quality, int &sellIn)
{
    isFresh(quality);

    if (sellIn < 0)
    {
        isFresh(quality);
    }
}

void sulfurasFunc(int &quality, int &sellIn)
{
    ++sellIn;
    isFresh(quality);
}

void backstageFunc(int &quality, int &sellIn)
{
    if (sellIn < 0)
    {
        quality = 0;
    }
    else if (sellIn < 5)
    {
        quality += 3;
    }
    else if (sellIn < 10)
    {
        quality += 2;
    }
    else
    {
        isFresh(quality);
    }
}

void GildedRose::updateQuality()
{
    const std::string aged = "Aged Brie";
    const std::string sulfuras = "Sulfuras, Hand of Ragnaros";
    const std::string backstage = "Backstage passes to a TAFKAL80ETC concert";

    for (auto &it : items)
    {
        --it.sellIn;

        if (it.name == aged)
        {
            agedFunc(it.quality, it.sellIn);
            continue;
        }

        if (it.name == sulfuras)
        {
            sulfurasFunc(it.quality, it.sellIn);
            continue;
        }

        if (it.name == backstage)
        {
            backstageFunc(it.quality, it.sellIn);
            continue;
        }

        if (it.quality > 0)
        {
            --it.quality;

            if (it.sellIn < 0)
            {
                --it.quality;
            }
        }
    }
}
