#include <string>
#include <vector>

class Item
{
public:
    ::std::string name;
    int sellIn;
    int quality;
    const bool isRegularItem = name != "Aged Brie" && name != "Sulfuras, Hand of Ragnaros" && name != "Backstage passes to a TAFKAL80ETC concert";
    Item(::std::string name, int sellIn, int quality) : name(::std::move(name)), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{

public:
    ::std::vector<Item> items;
    explicit GildedRose(::std::vector<Item> && items);
    explicit GildedRose(::std::vector<Item> const& items);

    void updateQuality();
};

