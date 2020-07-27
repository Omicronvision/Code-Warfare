#include "Optimizer.h"

Optimizer::Optimizer(std::string name, Int32 ID):
building(name, ID), optimization(0)
{}

Int32 Optimizer::getOptimization()
{
	return optimization;
}