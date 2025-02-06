#pragma once

namespace hIKipau {

    class State {
    public:
        virtual void Init() = 0;
        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;

        virtual void Pause(){} // Сделать чисто виртуальной, если требуется
        virtual void Resume() {}
        // virtual ~State() {} // Виртуальный деструктор
    };

}