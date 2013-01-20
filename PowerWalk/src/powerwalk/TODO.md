TODO-list
=========

This document lists the tasks that need to be done.
Also check the README.md file for a global idea of the current development plan.

Legend
[c] means that the list item is a class name that has to be implemented
[m] means that the list item is a method name that has to be implemented
[i] means that the list item is a interface name that has to be implemented

general
-------
- Add JavaDoc comments to public methods that don't have it.
- write documentation about the top-level methods of powerwalk

powerwalk.model
---------------

- Make subclasses of GameObject that represent objects in the RSBot environment (low priority).

- powerwalk.model.world.resources
    - [c] MAYBE? : Farmpatches extends AbstractResource ????

- Interactions and Teleports (->VINCENT)
    - test each interaction, so that it always works.
    - transportable factory (-> PATRICK)

- Item manager

- Refactor Point.f_score to a HashMap in powerwalk.control.PathFinder, since 
  it's really only used there.

- Move int[] values field values to own XML file and make values field non-final to 
  make it extendible.

powerwalk.data
--------------
- Data toevoegen (-> PATRICK & VINCENT)

powerwalk.task
--------------
- Meer tasks?
