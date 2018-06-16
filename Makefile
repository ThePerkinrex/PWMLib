buildDir := build/

build: $(buildDir)PWM.zip

$(buildDir)PWM.zip:
	@zip -x "$(buildDir)" -x .gitignore -x .git/ .git/**\* -x Makefile -r "$(buildDir)PWM.zip" .

clean:
	@rm -r $(buildDir)*

setup:
	@mkdir "$(buildDir)"
