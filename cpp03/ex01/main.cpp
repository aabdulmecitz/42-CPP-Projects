#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ScavTraps ===" << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2("Protector");
    
    std::cout << "\n=== Testing ScavTrap abilities ===" << std::endl;
    std::cout << "Guardian HP: " << scav1.get_hp() << ", EP: " << scav1.get_ep() << ", Attack: " << scav1.get_attack_d() << std::endl;
    std::cout << "Protector HP: " << scav2.get_hp() << ", EP: " << scav2.get_ep() << ", Attack: " << scav2.get_attack_d() << std::endl;
    
    std::cout << "\n=== Testing attacks ===" << std::endl;
    scav1.attack("Enemy1");
    scav2.attack("Enemy2");
    
    std::cout << "\n=== Testing damage ===" << std::endl;
    scav1.takeDamage(30);
    scav2.takeDamage(150); // More than HP
    
    std::cout << "\n=== Testing repair ===" << std::endl;
    scav1.beRepaired(20);
    scav2.beRepaired(10); // Should fail because HP is 0
    
    std::cout << "\n=== Testing Gate keeper mode ===" << std::endl;
    scav1.guardGate();
    scav2.guardGate();
    
    std::cout << "\n=== Testing with no energy ===" << std::endl;
    // Drain energy by attacking multiple times
    for (int i = 0; i < 50; i++) {
        scav1.attack("Target");
    }
    scav1.attack("Should fail"); // Should fail due to no energy
    scav1.beRepaired(5); // Should fail due to no energy
    
    std::cout << "\n=== Testing default constructor ===" << std::endl;
    ScavTrap defaultScav;
    defaultScav.attack("TestEnemy");
    defaultScav.guardGate();
    
    std::cout << "\n=== Destruction order ===" << std::endl;
    return 0;
}