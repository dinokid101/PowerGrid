/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QString>
#include <QMap>
#include "entity/component.h"


/**
 * \brief Contains classes related to the Entity framework.
 *
 * The Entity framework drives the higher level API, by representing Runescape
 * objects as collections of properties.
 *
 * \author Patrick Kramer
 */
namespace entity {


class World;

/**
 * \brief The Entity class
 *
 * This class represents an Entity in the runescape world.
 * Properties can be added to Entities in the form of Components.
 *
 * Entities should always be created to be a part of a World instance.
 * Therefore, either provide a World* in the constructor, or invoke
 * World::createEntity() create Entities.
 *
 * The constructor of Entity will throw a std::logic_error when the
 * provided World parameter is invalid.
 *
 * \see entity::Component
 * \see entity::World
 * \author Patrick Kramer
 */
class Entity : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Entity)
private:
    QMap<QString, Component*> components; // maps className => Component

    friend class World;
public:

    /**
     * \brief Creates a new Entity
     * \param parent the parent of this Entity
     */
    explicit Entity(World *parent = 0);

    /**
     * \brief Finds the Component of the given type.
     *
     * Suppose there is an Entity named e and a Component
     * type named \c MyComponent. Then the following invocation
     * would return the component of the \c MyComponent type:
     *     MyComponent* myComp = e->get<MyComponent>();
     *
     * \return a pointer to the requested Component
     *         type, or NULL if this Entity has no
     *         Component of that Type.
     */
    template<typename Type> Type* get() {
        return qobject_cast<Type*>(get(Type::staticMetaObject.className()));
    }

    /**
     * \brief Finds the Component of the given type
     *
     * \param name the name of the component type, as given by a
     *        component's \c getMetaObject()->className().
     */
    Component* get(QString name) Q_REQUIRED_RESULT;

    /**
     * \brief Returns whether a Component of the given Type exists.
     *
     * This is a convenience wrapper around \c has(QString name) that automatically
     * calls this function with the name of the provided type.
     *
     * \return true if a Component with the given type exists, false otherwise.
     */
    template<typename Type> bool has() {
        return has(Type::staticMetaObject.className());
    }

    /**
     * \brief Returns whether a Component type with the given name exists.
     * \return true if a Component type with the given name exists.
     */
    bool has(QString name) Q_REQUIRED_RESULT;

signals:

    /**
     * @brief Signal emitted when a Component has been added
     * @param cmp the added Component
     * @param e the Entity the Component is added to
     */
    void componentAdded(Entity* e, Component* cmp);

    /**
     * @brief Signal emitted when a Component has been removed
     * @param cmp the removed Component
     * @param e the Entity the Component is removed from
     */
    void componentRemoved(Entity* e, Component* cmp);

public slots:

    /**
     * @brief Adds the given Component to this Entity.
     *
     * This causes this Entity to emit the \c componentAdded(Component*) signal
     * Set overwrite to true to allow overwriting. When a Component is
     * overwritten, a @c componentRemoved(Component*) is also emitted before the new
     * Component is added.
     *
     * This slot does nothing if overwrite is false, and a Component with the same type
     * is already assigned to this Entity, or if the provided Component is NULL.
     *
     * @param cmp the Component to add.
     * @param overwrite (optional) true to allow overwriting any existing Component
     *        of the same type, false to prevent this. The default is false.
     */
    void addComponent(Component* cmp, bool overwrite=false);

    /**
     * @brief Removes the given Component from this Entity
     *
     * This causes this Entity to emit the \c componentRemoved(Component*) signal.
     * This slot does nothing if the specified Component is NULL or if the Component
     * does not belong to this Entity.
     *
     * @param cmp the Component to remove
     */
    void removeComponent(Component* cmp);
};

}

#endif // ENTITY_H
