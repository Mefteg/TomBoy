#include "basicrandomizer.h"

BasicRandomizer::BasicRandomizer(IRandomDriver * randomDriver)
    : m_randomDriver(randomDriver)
{
}

BasicRandomizer::~BasicRandomizer()
{
}

void BasicRandomizer::setSeed(int seed) const
{
    m_randomDriver->setSeed(seed);
}

int BasicRandomizer::getBetween(int min, int max) const
{
    return m_randomDriver->getBetween(min, max);
}
