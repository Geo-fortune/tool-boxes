## Internationalization
Einglish | [中文文档](README_zh.md)

## Introduction
---
Designe patterns are solutions to recurring problems; **guidelines on how to tackle certain problems**. They are not classes, packages or libraries that you can plug into your application and wait for the magic to happen. **These are guidelines on how to tackle certain problems in certain situations**.

Wikipedia describes them as:
> In software engineering, a software design pattern is a general reusable solution to a commonly occurring problem within a given context in software design. It is not a finished design that can be transformed directly into source or machine code. It is a description or template for how to solve a problem that can be used in many different situations.

⚠️ Be Careful
-----------------
- Design patterns are not a silver bullet to all your problems.
- Do not try to force them; bad things are supposed to happen, if done so. 
- Keep in mind that design patterns are solutions **to** problems, not solutions **finding** problems; so don't overthink.
- If used in a correct place in a correct manner, they can prove to be a savior; or else they can result in a horrible mess of a code.

## Type of Design Patterns

- [Creational](#creational-design-patterns)
- Structural
- Behavioral

### Creational Design Patterns
In plain words
> Creational patterns are focused towards how to instantiate an object or group of related objects.

Wikipedia says
> In software engineering, creational design patterns are design patterns that deal with object creation mechanisms, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or added complexity to the design. Creational design patterns solve this problem by somehow controlling this object creation.
- [Simple Factory]()
- [Factory]()
- [Abstract Factory]()
- [Builder]()
- [Prototype]()
- [Singleton](#singleton)


💍 Singleton
----
> There can only be one president of a country at a time. The same president has to be brought to action, whenever duty calls. In Plain words: Ensures that only one object of a particular class is ever created.

Wikipedia:
> In software engineering, the singleton pattern is a software design pattern that restricts the instantiation of a class to one object. This is useful when exactly one object is needed to coordinate actions across the system.

Singleton pattern is actually considered an anti-pattern and overuse of it should be avoided. It is not necessarily bad and could have some valid use-cases but should be used with caution because it introduces a global state in your application and change to it in one place could affect in the other areas and it could become pretty difficult to debug. The other bad thing about them is it makes your code tightly coupled plus mocking the singleton could be difficult.

**Programmatic Example**
To create a singleton, make the constructor private, disable cloning, disable extension and create a static variable to house the instance.

```c++
class President{

}

```


### Structural Design Patterns
