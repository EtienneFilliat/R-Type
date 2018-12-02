/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** PlayerSystem
*/

#ifndef PLAYERSYSTEM_HPP_
	#define PLAYERSYSTEM_HPP_

    #include "ASystem.hpp"
    #include "SafeQueue.hpp"
    #include "Constants.hpp"
    #include "EntityManager.hpp"
    #include "Components/Position.hpp"
    #include "Network/StreamBuffer/UDPClientStreamBuffer.hpp"

namespace Ecs {

    class PlayerSystem : public ASystem {
        public:
            PlayerSystem(std::list<std::shared_ptr<Entity>> &entities, std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> queue);
            void run() final;

        private:
            void handlePlayerAction(std::shared_ptr<Entity> entity);
            void movePlayer(std::shared_ptr<Entity> entity, int dir);
            void handleShoot(std::shared_ptr<Ecs::Position> pos);

            std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> _actionQueue;
    };
}
#endif /* !PLAYERSYSTEM_HPP_ */
