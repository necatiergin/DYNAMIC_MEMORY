```
using new_handler = void (*)(void);
new_handler set_new_handler(new_handler);
```
#### standart kütüphanenin _std::set_new_handler_ işleviyle kayıt edilen fonksiyon neler yapabilir?

+ Öyle bir koda sahiptir ki o kod çalıştığında artık _operator new_ fonksiyonu başarılı olur. Örneğin önceden _(rezerve olarak)_ edinilmiş bir bellek bloğunu geri verir.

+ _set_new_handler_ işlevini _nullptr_ argümanı ile çağırır. Böylece _operator new_ _std::bad_alloc_ türünden bir hata nesnesi gönderir.

+ Kendisi _std::bad_alloc_ ya da _std::bad_alloc_ sınıfından kalıtım yoluyla elde edilmiş bir sınıf türünden hata nesnesi gönderir.

+ Kendisi (yer açma konusunda) başarısız olduğundan bir başka _"handler"_ fonksiyonu kayıt eder.
