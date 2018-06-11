#include <exotica/Exotica.h>
#include <iostream>

using namespace exotica;

int main(int argc, char **argv) {
  {
    PlanningProblem_ptr problem = XMLLoader::loadProblem(
        "{exotica_valkyrie_collision_checking_example}/resources/"
        "val_collision_check_config.xml");
    auto q_rand = problem->getScene()->getSolver().getRandomControlledState();

    Timer timer;

    problem->getScene()->Update(q_rand);
    bool isValid = problem->getScene()->getCollisionScene()->isStateValid(true);

    HIGHLIGHT("Collision check in " << timer.getDuration()
                                    << "s. Collision check: " << isValid);
  }
  Setup::Destroy();
}