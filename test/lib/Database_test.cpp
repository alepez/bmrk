#include <gtest/gtest.h>
#include <Database.hpp>

struct DatabaseTest : public testing::Test {
	Config config {{}};
	Database db{config};
	void SetUp() {
	}
	void TearDown() {
	}
};
