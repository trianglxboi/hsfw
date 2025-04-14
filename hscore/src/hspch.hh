#ifndef HSFW_HSPCH_HH
#define HSFW_HSPCH_HH

#include "hscore/core/base.hh"

#ifdef HS_PLATFORM_WINDOWS
	#include <Windows.h>
#elif defined HS_PLATFORM_LINUX
	#include <unistd.h>
	#include <linux/limits.h>
#endif

#include <unordered_map>
#include <unordered_set>
#include <string_view>
#include <filesystem>
#include <functional>
#include <optional>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <variant>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <random>
#include <limits>
#include <bitset>
#include <mutex>
#include <regex>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <any>
#include <new>

#endif // HSFW_HSPCH_HH
