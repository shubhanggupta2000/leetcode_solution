class Foo
{
private:
   int flag = 1;
public:
   void first(function<void()> printFirst) {
       printFirst();
       flag++;
   }

   void second(function<void()> printSecond) {
       while (flag <= 1);
       printSecond();
       flag++;
   }

   void third(function<void()> printThird) {
       while (flag <= 2);
       printThird();
   }
};