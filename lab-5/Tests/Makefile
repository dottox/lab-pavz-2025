# Carpeta donde están los objetos ya compilados de las clases
OUTPUT_DIR := ../output
OUTPUT_OBJS := $(filter-out $(OUTPUT_DIR)/main.o, $(wildcard $(OUTPUT_DIR)/*.o))

# Carpeta para salida de tests
TEST_OUTPUT_DIR := ../output_tests

# Archivos fuente de tests (con ruta completa)
TEST_SRCS := $(wildcard clases/**/*.cpp datatypes/**/*.cpp utils/*.cpp) main_test.cpp

# Archivos objeto de test en output_tests con el mismo nombre base
TEST_OBJS := $(addprefix $(TEST_OUTPUT_DIR)/, $(notdir $(TEST_SRCS:.cpp=.o)))

# Asociar nombre base con ruta completa (clave para compilar bien)
define make-rule
$(TEST_OUTPUT_DIR)/$(notdir $(1:.cpp=.o)): $(1)
	@mkdir -p $(TEST_OUTPUT_DIR)
	g++ -c $$< -o $$@
endef

# Generar reglas para cada archivo fuente
$(foreach src,$(TEST_SRCS),$(eval $(call make-rule,$(src))))

# Target principal: compilar y linkear
tests: $(TEST_OBJS) $(OUTPUT_OBJS)
	@mkdir -p $(TEST_OUTPUT_DIR)
	g++ -o $(TEST_OUTPUT_DIR)/tests.exe $^
	@echo "Tests compiled successfully."
	$(TEST_OUTPUT_DIR)/tests.exe

# Limpieza
clean:
	rm -rf $(TEST_OUTPUT_DIR)

run: 
	$(TEST_OUTPUT_DIR)/tests.exe

.PHONY: clean tests