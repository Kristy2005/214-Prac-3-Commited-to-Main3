CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

COVFLAGS = -std=c++11 -Wall -Wextra --coverage -fprofile-arcs -ftest-coverage -O0

TARGET     = eventflow
COV_TARGET = eventflow_cov

SRCS = main.cpp \
       Subject.cpp \
       Observer.cpp \
       EventComponent.cpp \
       EventUnit.cpp \
       EventGroup.cpp \
       EventControl.cpp \
       Notice.cpp \
       Stage.cpp \
       EntranceGate.cpp \
       StageGate.cpp \
       Bar.cpp \
       FoodVendor.cpp \
       SecurityTeam.cpp \
       MedicalTeam.cpp

OBJS     = $(SRCS:.cpp=.o)
COV_DIR  = cov_build
COV_OBJS = $(addprefix $(COV_DIR)/,$(SRCS:.cpp=.o))

# ──────────────────────────────────────────
# Default build
# ──────────────────────────────────────────
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ──────────────────────────────────────────
# Run the engine
#   make run
# ──────────────────────────────────────────
run: $(TARGET)
	./$(TARGET)

# ──────────────────────────────────────────
# Valgrind — full memory-leak check
#   make valgrind
# ──────────────────────────────────────────
valgrind: $(TARGET)
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--error-exitcode=1 \
		./$(TARGET)

# ──────────────────────────────────────────
# Coverage build + terminal summary
#   make coverage
# ──────────────────────────────────────────
$(COV_DIR):
	mkdir -p $(COV_DIR)

$(COV_DIR)/%.o: %.cpp | $(COV_DIR)
	$(CXX) $(COVFLAGS) -c $< -o $@

$(COV_TARGET): $(COV_OBJS)
	$(CXX) $(COVFLAGS) -o $(COV_TARGET) $(COV_OBJS)

coverage: $(COV_TARGET)
	./$(COV_TARGET)
	gcov --object-directory $(COV_DIR) $(SRCS)

# ──────────────────────────────────────────
# Coverage HTML report (requires lcov)
#   make coverage-html
# ──────────────────────────────────────────
coverage-html: $(COV_TARGET)
	./$(COV_TARGET)
	lcov --capture --directory $(COV_DIR) --output-file coverage.info \
		--rc lcov_branch_coverage=1
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage --branch-coverage
	@echo "Report ready: open coverage/index.html"

# ──────────────────────────────────────────
# Clean
# ──────────────────────────────────────────
clean:
	rm -f $(OBJS) $(TARGET) $(COV_TARGET)
	rm -rf $(COV_DIR)
	rm -f *.gcov coverage.info
	rm -rf coverage/

.PHONY: all run valgrind coverage coverage-html clean