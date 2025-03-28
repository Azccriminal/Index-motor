#ifndef LOAD_H
#define LOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // access()

// Kullanıcı dosyasını tanımlayan yapı
typedef struct {
    char *path;          // Dosya yolu
    int control_flag;    // Dosya kontrol bayrağı (örneğin geçerlilik kontrolü)
} userfile_t;

// Fonksiyonlar
userfile_t *create_userfile(const char *path, int control_flag);
void free_userfile(userfile_t *uf);
int validate_userfile(userfile_t *uf);

// Kontrol bayrağını yöneten yapı
typedef struct {
    int defcontrol;   // Varsayılan kontrol bayrağı
} control_t;

// Fonksiyonlar
control_t *create_control(int defcontrol);
int is_control_valid(control_t *ctrl);
void free_control(control_t *ctrl);

// Tokenizer, etiket çözümleme işlemi yapacak yapı
typedef struct {
    char *token;   // Token değerini tutar
} tokenizer_t;

// Fonksiyonlar
tokenizer_t *create_tokenizer(const char *token);
int resolve_token(tokenizer_t *tok, const char *base_path);
void free_tokenizer(tokenizer_t *tok);

// Kullanıcı oturumu oluşturma
typedef struct {
    void *itemload;  // Yükleme yapılacak içerik
} do_session_t;

// Fonksiyonlar
do_session_t *create_do_session(void *itemload);
void *get_session_item(do_session_t *session);
void free_do_session(do_session_t *session);

// Dosya türlerine yönelik yapılar
typedef struct {
    do_session_t do_session;  // Document için oturum
} file_document_t;

typedef struct {
    do_session_t do_session;  // Fotoğraf için oturum
} file_photoimage_t;

typedef struct {
    do_session_t do_session;  // Video için oturum
} file_video_t;

typedef struct {
    do_session_t do_session;  // Metin dosyaları için oturum
} file_txtline_t;

// Yaratma fonksiyonları
file_document_t *create_file_document(void *itemload);
file_photoimage_t *create_file_photoimage(void *itemload);
file_video_t *create_file_video(void *itemload);
file_txtline_t *create_file_txtline(void *itemload);

// Serbest bırakma fonksiyonları
void free_file_document(file_document_t *doc);
void free_file_photoimage(file_photoimage_t *photo);
void free_file_video(file_video_t *video);
void free_file_txtline(file_txtline_t *txtline);

// Hedef URL'leri tutan yapı
typedef struct {
    char *photo_image;  // Fotoğraf linki
    char *video_image;  // Video linki
    char *txtline_file; // Metin dosyası linki
} href_t;

// Fonksiyonlar
href_t *create_href(const char *photo, const char *video, const char *txtline);
void free_href(href_t *href);

// Fotoğraf objesi
typedef struct {
    void *herfsession;  // Bağlantı oturumu
} photo_obj;

photo_obj *create_photo_obj(void *herfsession);
void free_photo_obj(photo_obj *photo);

// Medya objesi
typedef struct {
    void *usersession;  // Video oturumu
} media_obj;

media_obj *create_media_obj(void *usersession);
void free_media_obj(media_obj *media);

// Metin dosyası objesi
typedef struct {
    void *userdefsession;  // Metin dosyası oturumu
} txt_file;

txt_file *create_txt_file(void *userdefsession);
void free_txt_file(txt_file *txt);

// Birden fazla öğeyi birleştiren yapı
typedef struct {
    file_document_t *document; // <iframe>, <object>
    file_photoimage_t *photo;  // <img>
    file_video_t *video;       // <video>
    file_txtline_t *txtline;   // <pre> <code>
} session_mod;

// Fonksiyonlar
session_mod *create_session_mod(file_document_t *doc, file_photoimage_t *photo, file_video_t *video, file_txtline_t *txtline);
void free_session_mod(session_mod *session);

// Yükleme paketi
typedef struct {
    href_t *href;        // Bağlantılar
    session_mod *session; // İçerik oturumu
} loader_package_t;

// Fonksiyonlar
loader_package_t *create_loader_package(href_t *href, session_mod *session);
void free_loader_package(loader_package_t *package);

#endif // LOAD_H
