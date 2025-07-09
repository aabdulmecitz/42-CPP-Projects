#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== Testing Construction/Destruction Chain ===" << std::endl;
    {
        std::cout << "Creating FragTrap:" << std::endl;
        FragTrap frag("Destroyer");
        std::cout << "\nDestroying FragTrap:" << std::endl;
    }
    
    std::cout << "\n=== Testing FragTrap Values ===" << std::endl;
    FragTrap frag1("Bomber");
    std::cout << "HP: " << frag1.get_hp() << " (should be 100)" << std::endl;
    std::cout << "EP: " << frag1.get_ep() << " (should be 100)" << std::endl;
    std::cout << "Attack: " << frag1.get_attack_d() << " (should be 30)" << std::endl;

    std::cout << "\n=== Testing FragTrap Abilities ===" << std::endl;
    frag1.attack("Enemy");
    frag1.takeDamage(50);
    frag1.beRepaired(20);
    frag1.highFivesGuys();

    std::cout << "\n=== Comparing with ScavTrap ===" << std::endl;
    ScavTrap scav("Guardian");
    std::cout << "ScavTrap HP: " << scav.get_hp() << ", EP: " << scav.get_ep() << ", Attack: " << scav.get_attack_d() << std::endl;
    scav.guardGate();
    
    std::cout << "\n=== Testing Default Constructor ===" << std::endl;
    FragTrap defaultFrag;
    defaultFrag.highFivesGuys();
    
    std::cout << "\n=== Program End (Destruction Order) ===" << std::endl;

    std::cout << "=== Testing DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Diamond");
    
    std::cout << "\nDiamondTrap stats:" << std::endl;
    std::cout << "HP: " << diamond.get_hp() << " (should be 100)" << std::endl;
    std::cout << "EP: " << diamond.get_ep() << " (should be 50)" << std::endl;
    std::cout << "Attack: " << diamond.get_attack_d() << " (should be 30)" << std::endl;
    
    std::cout << "\nTesting DiamondTrap abilities:" << std::endl;
    diamond.attack("Enemy");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    
    return 0;
}