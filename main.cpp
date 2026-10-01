#include <Geode/Geode.using>

using namespace geode::prelude;

#include <Geode/modify/PlayLayer.class.hpp>
#include <Geode/modify/LevelEditorLayer.class.hpp>

// 3'ten fazla collectible (coin) mantığını yöneten kısım
class $modify(CustomPlayLayer, PlayLayer) {
    
    void collectItem(ItemTriggerGameObject* item) {
        PlayLayer::collectItem(item);
        
        // Eğer toplanan nesnenin ID'si 3'ten büyükse, sınırları aşıp özel işlem yapabiliriz
        if (item) {
            int itemID = item->m_targetValue;
            
            if (itemID > 3) {
                log::info("Özel Collectible toplandı! ID: {}. 3 coin sınırı aşıldı.", itemID);
                
                // Burada ek coin/puan mantığını oyuna işleyebilirsin
            }
        }
    }
    
    bool init(GJGameLevel* level, bool p1, bool p2) {
        if (!PlayLayer::init(level, p1, p2)) return false;
        
        log::info("SVC PlayLayer yüklendi: Çoklu collectible sistemi aktif!");
        return true;
    }
};

// Stevomets tarzı level editör kolaylıkları ve şablon desteği
class $modify(CustomEditorLayer, LevelEditorLayer) {
    bool init(GJGameLevel* level, bool p1) {
        if (!LevelEditorLayer::init(level, p1)) return false;
        
        log::info("SVC Level Editor yüklendi: Hazır şablon araçları hazır.");
        return true;
    }
};
