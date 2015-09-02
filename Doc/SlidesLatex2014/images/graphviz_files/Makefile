OUT_FILES=$(patsubst %.dot, ../%.png, $(wildcard *.dot))

.PHONY: all
all: $(OUT_FILES)

../%.png: %.dot
	dot -T png $^ -o $@

clean:
	$(RM) $(OUT_FILES)
