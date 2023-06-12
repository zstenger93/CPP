#include "../includes/BrainDamage.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

static void AvailableTestCases() {
	std::cout << BAD_INPUT << std::endl << std::endl;
	std::cout << TEST0 << std::endl;
	std::cout << TEST1 << std::endl;
	std::cout << TEST2 << std::endl;
	std::cout << TEST3 << std::endl;
	std::cout << TEST4 << std::endl;
	std::cout << TEST5 << std::endl;
}

static void OverKill() {
	IMateriaSource* src = new MateriaSource();
	ICharacter* project = new Character("project");
	ICharacter* brain = new Character("brain");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	int i = 0, d = 0;

	while (i < INVENTORY_SIZE && d < SLOTS) {
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
		src->learnMateria(new BrainDamage());
		tmp = src->createMateria("braindamage");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
	}

	project->use(0, *brain);
	project->use(1, *brain);
	project->use(2, *me);

	delete me;
	delete brain;
	delete project;
	delete src;
}

static void TestUnEquip() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* EquipMaster = new Character("EquipMaster");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	EquipMaster->equip(tmp);
	tmp = src->createMateria("cure");
	EquipMaster->equip(tmp);
	ICharacter* brain = new Character("brain");
	EquipMaster->use(0, *brain);
	EquipMaster->unequip(1);
	EquipMaster->use(1, *brain);

	delete brain;
	delete EquipMaster;
	delete src;
}

static void TestForMissingItem() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* MissingItem = new Character("MissingItem");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	MissingItem->equip(tmp);
	tmp = src->createMateria("cure");
	MissingItem->equip(tmp);
	ICharacter* brain = new Character("brain");
	MissingItem->use(2, *brain);
	MissingItem->use(3, *brain);
	delete brain;
	delete MissingItem;
	delete src;
}

static void TestForWrongIndex() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* WrongIndex = new Character("WrongIndex");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	WrongIndex->equip(tmp);
	tmp = src->createMateria("cure");
	WrongIndex->equip(tmp);
	ICharacter* brain = new Character("brain");
	WrongIndex->use(-3, *brain);
	WrongIndex->use(5, *brain);
	delete brain;
	delete WrongIndex;
	delete src;
}

static void TestForWrongSpells() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* WrongSpells = new Character("WrongSpells");
	AMateria* tmp;
	tmp = src->createMateria("Ice");
	WrongSpells->equip(tmp);
	tmp = src->createMateria("Cure");
	WrongSpells->equip(tmp);
	ICharacter* brain = new Character("brain");
	WrongSpells->use(0, *brain);
	WrongSpells->use(1, *brain);
	delete brain;
	delete WrongSpells;
	delete src;
}

static void TestFromPdf() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* project = new Character("project");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	project->equip(tmp);
	tmp = src->createMateria("cure");
	project->equip(tmp);
	ICharacter* brain = new Character("brain");
	project->use(0, *brain);
	project->use(1, *brain);
	delete brain;
	delete project;
	delete src;
}

static int GetId(int argc, char** argv, int TestCaseId) {
	if (argc > 1) {
		int input = std::atoi(argv[1]);
		if (input < 0 || input > 5) return AvailableTestCases(), exit(1), 1;
		for (int i = 1; i >= 0; i++) {
			if (i == input) {
				TestCaseId = i;
				return TestCaseId;
				;
			}
		}
	}
	return TestCaseId;
}

int main(int argc, char** argv) {
	int TestCaseId = GetId(argc, argv, 0);

	switch (TestCaseId) {
		case 1:
			TestForWrongSpells();
			break;
		case 2:
			TestForWrongIndex();
			break;
		case 3:
			TestForMissingItem();
			break;
		case 4:
			TestUnEquip();
			break;
		case 5:
			OverKill();
			break;
		default:
			TestFromPdf();
			break;
	}
	return 0;
}