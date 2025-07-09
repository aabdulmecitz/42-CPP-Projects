#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creating FragTraps ===" << std::endl;
    FragTrap frag1("Destroyer");
    FragTrap frag2("Bomber");
    
    std::cout << "\n=== Testing FragTrap abilities ===" << std::endl;
    std::cout << "Destroyer HP: " << frag1.get_hp() << ", EP: " << frag1.get_ep() << ", Attack: " << frag1.get_attack_d() << std::endl;
    std::cout << "Bomber HP: " << frag2.get_hp() << ", EP: " << frag2.get_ep() << ", Attack: " << frag2.get_attack_d() << std::endl;
    
    std::cout << "\n=== Testing attacks ===" << std::endl;
    frag1.attack("Enemy1");
    frag2.attack("Enemy2");
    
    std::cout << "\n=== Testing damage ===" << std::endl;
    frag1.takeDamage(30);
    frag2.takeDamage(150); // More than HP would kill normal ClapTrap
    
    std::cout << "\n=== Testing repair ===" << std::endl;
    frag1.beRepaired(20);
    frag2.beRepaired(10);
    
    std::cout << "\n=== Testing High Five ability ===" << std::endl;
    frag1.highFivesGuys();
    frag2.highFivesGuys();
    
    std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
    {
        std::cout << "Creating ScavTrap:" << std::endl;
        ScavTrap scav("Guardian");
        std::cout << "Creating FragTrap:" << std::endl;
        FragTrap frag("Exploder");
        
        std::cout << "Testing abilities:" << std::endl;
        scav.guardGate();
        frag.highFivesGuys();
        
        std::cout << "Leaving scope (destruction order):" << std::endl;
    }
    
    std::cout << "\n=== Testing default constructor ===" << std::endl;
    FragTrap defaultFrag;
    defaultFrag.attack("TestEnemy");
    defaultFrag.highFivesGuys();
    
    std::cout << "\n=== Destruction order ===" << std::endl;
    return 0;
}