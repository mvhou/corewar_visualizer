.name	"Baking Apple Pie"
.comment		"Flour, Apple, Cinnamon, Sugar, Buttter"

recipe:
		live %10
		fork	%3
		add r1, r5, r4
		zjmp %:baking

baking:
		live %3
		ld 5, r5
		zjmp %:recipe
