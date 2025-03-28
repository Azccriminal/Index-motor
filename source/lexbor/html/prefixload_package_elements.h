#include "load.h"
#include <base64.h>  // Base64 encoding için dış kütüphane örneği

// Kullanıcı dosyasını oluşturma fonksiyonu
userfile_t *create_userfile(const char *path, int control_flag) {
    userfile_t *uf = (userfile_t *)malloc(sizeof(userfile_t));
    if (uf == NULL) {
        return NULL;
    }
    uf->path = strdup(path);
    uf->control_flag = control_flag;
    return uf;
}

// Kullanıcı dosyasını serbest bırakma fonksiyonu
void free_userfile(userfile_t *uf) {
    if (uf != NULL) {
        free(uf->path);
        free(uf);
    }
}

// Kullanıcı dosyasının geçerliliğini kontrol etme fonksiyonu
int validate_userfile(userfile_t *uf) {
    if (uf == NULL || uf->path == NULL) {
        return 0;
    }
    return access(uf->path, F_OK) != -1;  // Dosyanın mevcut olup olmadığını kontrol et
}

// Kontrol bayrağını oluşturma fonksiyonu
control_t *create_control(int defcontrol) {
    control_t *ctrl = (control_t *)malloc(sizeof(control_t));
    if (ctrl == NULL) {
        return NULL;
    }
    ctrl->defcontrol = defcontrol;
    return ctrl;
}

// Kontrol bayrağını doğrulama fonksiyonu
int is_control_valid(control_t *ctrl) {
    return (ctrl != NULL && ctrl->defcontrol >= 0);  // Negatif olmayan bir bayrak
}

// Kontrol bayrağını serbest bırakma fonksiyonu
void free_control(control_t *ctrl) {
    free(ctrl);
}

// Tokenizer'ı oluşturma fonksiyonu
tokenizer_t *create_tokenizer(const char *token) {
    tokenizer_t *tok = (tokenizer_t *)malloc(sizeof(tokenizer_t));
    if (tok == NULL) {
        return NULL;
    }
    tok->token = strdup(token);
    return tok;
}

// Token çözümleme fonksiyonu
int resolve_token(tokenizer_t *tok, const char *base_path) {
    if (tok == NULL || base_path == NULL) {
        return 0;
    }
    // Token'ı base_path ile çözümleme işlemi
    return 1;  // Basit bir geçerlilik kontrolü
}

// Tokenizer'ı serbest bırakma fonksiyonu
void free_tokenizer(tokenizer_t *tok) {
    if (tok != NULL) {
        free(tok->token);
        free(tok);
    }
}

// Kullanıcı oturumunu oluşturma fonksiyonu
do_session_t *create_do_session(void *itemload) {
    do_session_t *session = (do_session_t *)malloc(sizeof(do_session_t));
    if (session == NULL) {
        return NULL;
    }
    session->itemload = itemload;
    return session;
}

// Oturumdan öğe alım fonksiyonu
void *get_session_item(do_session_t *session) {
    if (session != NULL) {
        return session->itemload;
    }
    return NULL;
}

// Kullanıcı oturumunu serbest bırakma fonksiyonu
void free_do_session(do_session_t *session) {
    free(session);
}

// Dosya türlerine yönelik yaratma fonksiyonları
file_document_t *create_file_document(void *itemload) {
    file_document_t *doc = (file_document_t *)malloc(sizeof(file_document_t));
    if (doc == NULL) {
        return NULL;
    }
    doc->do_session.itemload = itemload;
    return doc;
}

file_photoimage_t *create_file_photoimage(void *itemload) {
    file_photoimage_t *photo = (file_photoimage_t *)malloc(sizeof(file_photoimage_t));
    if (photo == NULL) {
        return NULL;
    }
    photo->do_session.itemload = itemload;
    return photo;
}

file_video_t *create_file_video(void *itemload) {
    file_video_t *video = (file_video_t *)malloc(sizeof(file_video_t));
    if (video == NULL) {
        return NULL;
    }
    video->do_session.itemload = itemload;
    return video;
}

file_txtline_t *create_file_txtline(void *itemload) {
    file_txtline_t *txtline = (file_txtline_t *)malloc(sizeof(file_txtline_t));
    if (txtline == NULL) {
        return NULL;
    }
    txtline->do_session.itemload = itemload;
    return txtline;
}

// Dosya türlerini serbest bırakma fonksiyonları
void free_file_document(file_document_t *doc) {
    free(doc);
}

void free_file_photoimage(file_photoimage_t *photo) {
    free(photo);
}

void free_file_video(file_video_t *video) {
    free(video);
}

void free_file_txtline(file_txtline_t *txtline) {
    free(txtline);
}

// Hedef URL'leri tutan yapıyı oluşturma fonksiyonu
href_t *create_href(const char *photo, const char *video, const char *txtline) {
    href_t *href = (href_t *)malloc(sizeof(href_t));
    if (href == NULL) {
        return NULL;
    }
    href->photo_image = strdup(photo);
    href->video_image = strdup(video);
    href->txtline_file = strdup(txtline);
    return href;
}

// Hedef URL'yi serbest bırakma fonksiyonu
void free_href(href_t *href) {
    if (href != NULL) {
        free(href->photo_image);
        free(href->video_image);
        free(href->txtline_file);
        free(href);
    }
}

// Fotoğraf objesi oluşturma fonksiyonu
photo_obj *create_photo_obj(void *herfsession) {
    photo_obj *photo = (photo_obj *)malloc(sizeof(photo_obj));
    if (photo == NULL) {
        return NULL;
    }
    photo->herfsession = herfsession;
    return photo;
}

// Fotoğraf objesini serbest bırakma fonksiyonu
void free_photo_obj(photo_obj *photo) {
    free(photo);
}

// Medya objesi oluşturma fonksiyonu
media_obj *create_media_obj(void *usersession) {
    media_obj *media = (media_obj *)malloc(sizeof(media_obj));
    if (media == NULL) {
        return NULL;
    }
    media->usersession = usersession;
    return media;
}

// Medya objesini serbest bırakma fonksiyonu
void free_media_obj(media_obj *media) {
    free(media);
}

// Metin dosyası objesi oluşturma fonksiyonu
txt_file *create_txt_file(void *userdefsession) {
    txt_file *txt = (txt_file *)malloc(sizeof(txt_file));
    if (txt == NULL) {
        return NULL;
    }
    txt->userdefsession = userdefsession;
    return txt;
}

// Metin dosyası objesini serbest bırakma fonksiyonu
void free_txt_file(txt_file *txt) {
    free(txt);
}

// Birden fazla öğeyi birleştiren yapıyı oluşturma fonksiyonu
session_mod *create_session_mod(file_document_t *doc, file_photoimage_t *photo, file_video_t *video, file_txtline_t *txtline) {
    session_mod *session = (session_mod *)malloc(sizeof(session_mod));
    if (session == NULL) {
        return NULL;
    }
    session->document = doc;
    session->photo = photo;
    session->video = video;
    session->txtline = txtline;
    return session;
}

// Birden fazla öğeyi birleştiren yapıyı serbest bırakma fonksiyonu
void free_session_mod(session_mod *session) {
    free(session);
}

// Yükleme paketini oluşturma fonksiyonu
loader_package_t *create_loader_package(href_t *href, session_mod *session) {
    loader_package_t *package = (loader_package_t *)malloc(sizeof(loader_package_t));
    if (package == NULL) {
        return NULL;
    }
    package->href = href;
    package->session = session;
    return package;
}

// Yükleme paketini serbest bırakma fonksiyonu
void free_loader_package(loader_package_t *package) {
    free(package);
}

// Encode işlemleri için ek fonksiyonlar
// Fotoğraf için Base64 encode
char *encode_photo_to_base64(const char *photo_path) {
    // Fotoğrafı Base64 formatında encode etme işlemi
    return base64_encode(photo_path);
}

// Video için Base64 encode
char *encode_video_to_base64(const char *video_path) {
    // Videoyu Base64 formatında encode etme işlemi
    return base64_encode(video_path);
}

// Metin dosyası için Base64 encode
char *encode_txt_to_base64(const char *txt_path) {
    // Metin dosyasını Base64 formatında encode etme işlemi
    return base64_encode(txt_path);
}
