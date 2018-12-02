/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Music
*/

#ifndef MUSIC_HPP_
	#define MUSIC_HPP_

    #include <SFML/Audio.hpp>

class Music {
	public:
		Music(const std::string &path);
		~Music();
        inline void play() { _music.play(); };
		inline void replay() { _music.stop(); _music.play(); };
		inline void stop() { _music.stop(); };
        inline void isRepeatable(bool repeat) { _music.setLoop(repeat); };
		inline void setVolume(float volume) { _music.setVolume(volume); };

	private:
        sf::Music _music;
};

#endif /* !MUSIC_HPP_ */
