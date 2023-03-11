#pragma once

#include <vector>

#include <entity_filter.h>
#include <entity.h>
#include <component_pool.h>

namespace wase::ecs
{
	class System
	{
	public:
		/**
		 * Default destructor.
		 */
		virtual ~System() = default;

		/**
		 * Update the system.
		 * 
		 * @param deltaTime Delta time.
		 */
		virtual void update(const float deltaTime);

		/**
		 * Add an entity to the system.
		 * 
		 * @param entity Entity to add.
		 */
		void addEntity(Entity* entity);

		/**
		 * Remove an entity from the system.
		 * 
		 * @param entity Entity to remove.
		 */
		void removeEntity(Entity* entity);

		/**
		 * Enable an entity in the system.
		 * 
		 * @param entity Entity to enable.
		 */
		void enableEntity(Entity* entity);

		/**
		 * Disable an entity in the system.
		 * 
		 * @param entity Entity to disable.
		 */
		void disableEntity(Entity* entity);

		/**
		 * Check if an entity still matches the system's filter.
		 * 
		 * @param entity Entity to check.
		 * @param componentMap The component map of the entity.
		 */
		void checkEntity(Entity* entity, const ComponentMap componentMap);

	protected:
		/**
		 * Get the EntityFilter of this system
		 */
		EntityFilter& getFilter();

	protected:
		std::vector<Entity*> m_EnabledEntities;
		std::vector<Entity*> m_DisabledEntities;
		ComponentPool* m_ComponentPool;
		
	private:
		EntityFilter m_Filter;

		friend class SystemPool;
	};
}