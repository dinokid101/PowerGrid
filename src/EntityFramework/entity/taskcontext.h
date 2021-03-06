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
#ifndef ENTITY_TASKCONTEXT_H
#define ENTITY_TASKCONTEXT_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>


#ifdef Q_COMPILER_LAMBDA
// Wraps `cond` in a lambda expression, capturing the current scope by value.
// The EVALUATE macro executes the lambda.
typedef bool Condition();
#define PG_COND(cond) [=](){ return (cond); }
#define EVALUATE(cond) (cond())

#else
// Wraps `cond` in a anonymous class that has an `evaluate()` function.
// The EVALUATE macro executes that function.
class Condition {
    virtual bool evaluate() = 0;
};
#define PG_COND(cond) (class : Condition {\
                            virtual bool evaluate() { return (cond); }\
                      })
#define EVALUATE(cond) (cond.evaluate())
#endif

namespace entity {

/**
 * @brief Utility class for Tasks
 *
 * This class provides convenience functions for performing waits.
 */
class TaskContext : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(TaskContext)
private:
    QMutex _mutex;
    QWaitCondition* _waiter;
public:
    /**
     * @brief Creates a new TaskContext.
     *
     * Normally, TaskContext instances are accessible to Tasks by their
     * @c context() member function. As such, Tasks never have to instantiate
     * objects of this type.
     *
     * @param parent - the parent QObject
     */
    explicit TaskContext(QObject *parent = 0);

    /**
     * @brief Waits until the provided condition evaluates to true.
     *
     * This function waits for updates in the World and keeps checking
     * the condition after each update until the expression becomes true.
     * This approach is preferred over waiting in a loop manually.
     *
     * This function works together with the @c PG_COND macro to form a
     * lambda expression which is then passed into this function.
     *
     * Example:
     *
     *     // Waits until the Player's level becomes at least 50.
     *     context()->waitUntil(PG_COND(RS::Client::getLocalPlayer().getLevel() >= 50));
     *
     * If your compiler does not support lambda expressions, define a
     * function that returns a bool result and pass a pointer to that
     * function in the function call.
     *
     * Example:
     *
     *     // The function testing the condition
     *     bool testPlayerLevel() {
     *         return RS::Client::getLocalPlayer().getLevel() >= 50;
     *     }
     *
     *     // Then, in a Task, call waitUntil with the function address:
     *     context()->waitUntil(&testPlayerLevel);
     *
     * @param condition - the condition to wait for.
     */
    void waitUntil(Condition condition);

    /**
     * context()->run<MyTask>();
     */
    template <typename T>
    void run() {
        T().execute(this);
    }

    /**
     * @brief Waits @c msecs milliseconds before returning.
     * @param msecs - the amount of time to wait.
     */
    void wait(ulong msecs);

signals:
    /**
     * @brief Signal emitted whenever the TaskContext starts waiting
     */
    void waitStarted();
    /**
     * @brief Signal emitted whenever the TaskContext stops waiting
     */
    void waitStopped();

public slots:
    /**
     * @brief Supply the QWaitCondition used by this TaskContext
     *
     * This is called automatically by the TaskManager that created
     * this TaskContext, so Tasks never have to call this function.
     *
     * @param waiter the QWaitCondition to use for this TaskContext.
     */
    void supplyWaitCondition(QWaitCondition* waiter);
};

} // namespace entity

#endif // ENTITY_TASKCONTEXT_H
