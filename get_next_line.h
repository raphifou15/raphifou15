/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:13:46 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/**
 * @file get_next_line.h
 * @brief Définitions des fonctions pour get_next_line.
 */

/**
 * @brief Lit une ligne d'un fichier descripteur.
 *
 * La fonction `get_next_line` lit une ligne d'un fichier descripteur et la stocke
 * dans la variable `line`.
 *
 * @param fd Le descripteur de fichier.
 * @param line Un pointeur vers la ligne.
 * @return 1 si une ligne a été lue, 0 si la fin du fichier a été atteinte,
 * -1 en cas d'erreur.
 */
int		get_next_line(int fd, char **line);

/**
 * @brief Duplique une chaîne de caractères.
 *
 * La fonction `ft_strdup` duplique une chaîne de caractères et retourne un pointeur
 * vers la nouvelle chaîne.
 *
 * @param s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Calcule la longueur d'une chaîne de caractères modifiée.
 *
 * La fonction `ft_strlen_modif` calcule la longueur d'une chaîne de caractères
 * en tenant compte du caractère de retour à la ligne.
 *
 * @param s La chaîne de caractères.
 * @param carriage Le caractère de retour à la ligne.
 * @return La longueur de la chaîne de caractères.
 */
int		ft_strlen_modif(const char *s, int carriage);

/**
 * @brief Recherche un caractère dans une chaîne de caractères.
 *
 * La fonction `ft_strchr` recherche le premier caractère `c` dans la chaîne
 * de caractères `s`.
 *
 * @param s La chaîne de caractères.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la première occurrence de `c` dans `s`, ou NULL
 * si `c` n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Concatène deux chaînes de caractères.
 *
 * La fonction `ft_strjoin` concatène deux chaînes de caractères et retourne
 * un pointeur vers la nouvelle chaîne.
 *
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Alloue de la mémoire pour une chaîne de caractères.
 *
 * La fonction `ft_str` alloue de la mémoire pour une chaîne de caractères et
 * retourne un pointeur vers la nouvelle chaîne.
 *
 * @param s La chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 */
char	*ft_str(char *s);

#endif
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:14:46 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file get_next_line.c
 * @brief Implémentation de la fonction get_next_line.
 */

/**
 * @brief Alloue de la mémoire pour une chaîne de caractères.
 * 
 * La fonction `ft_str` alloue de la mémoire pour une chaîne de caractères et 
 * retourne un pointeur vers la nouvelle chaîne.
 * 
 * @param s La chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 */
char	*ft_str(char *s)
{
	char	*new;

	if (!(new = malloc(sizeof(char) * (ft_strlen_modif(s, '\n') + 1))))
		return (NULL);
	ft_strncpy(new, s, ft_strlen_modif(s, '\n'));
	new[ft_strlen_modif(s, '\n')] = '\0';
	return (new);
}

/**
 * @brief Concatène deux chaînes de caractères.
 * 
 * La fonction `ft_strjoin` concatène deux chaînes de caractères et retourne 
 * un pointeur vers la nouvelle chaîne.
 * 
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Recherche un caractère dans une chaîne de caractères.
 * 
 * La fonction `ft_strchr` recherche le premier caractère `c` dans la chaîne 
 * de caractères `s`.
 * 
 * @param s La chaîne de caractères.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la première occurrence de `c` dans `s`, ou NULL 
 * si `c` n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

/**
 * @brief Calcule la longueur d'une chaîne de caractères modifiée.
 * 
 * La fonction `ft_strlen_modif` calcule la longueur d'une chaîne de caractères
 * en tenant compte du caractère de retour à la ligne.
 * 
 * @param s La chaîne de caractères.
 * @param carriage Le caractère de retour à la ligne.
 * @return La longueur de la chaîne de caractères.
 */
int		ft_strlen_modif(const char *s, int carriage)
{
	int i;

	i = 0;
	while (s[i] != carriage && s[i])
		i++;
	return (i);
}

/**
 * @brief Copie une chaîne de caractères.
 * 
 * La fonction `ft_strncpy` copie une chaîne de caractères dans une autre,
 * en prenant en compte la longueur spécifiée.
 * 
 * @param dest La chaîne de caractères de destination.
 * @param src La chaîne de caractères source.
 * @param n Le nombre de caractères à copier.
 * @return La chaîne de caractères de destination.
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * @brief Duplique une chaîne de caractères.
 * 
 * La fonction `ft_strdup` duplique une chaîne de caractères et retourne un pointeur
 * vers la nouvelle chaîne.
 * 
 * @param s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Lit une ligne d'un fichier descripteur.
 *
 * La fonction `get_next_line` lit une ligne d'un fichier descripteur et la stocke 
 * dans la variable `line`.
 *
 * @param fd Le descripteur de fichier.
 * @param line Un pointeur vers la ligne.
 * @return 1 si une ligne a été lue, 0 si la fin du fichier a été atteinte, 
 * -1 en cas d'erreur.
 */
int		get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
		read(fd, NULL, 0) < 0)
		return (-1);
	if (buf && ft_strchr(buf, '\n'))
	{
		*line = ft_str(buf);
		tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
		free(buf);
		buf = tmp;
		return (1);
	}
	ret = 1;
	while (ret > 0 && !ft_strchr(buf, '\n'))
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			return (-1);
		ret = read(fd, tmp, BUFFER_SIZE);
		tmp[ret] = '\0';
		buf = ft_strjoin(buf, tmp);
		free(tmp);
	}
	if (buf)
	{
		*line = ft_str(buf);
		free(buf);
		buf = NULL;
	}
	if (ret == 0 && *line == NULL)
		return (0);
	return (1);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:12:00 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_split.c
 * @brief Implémentation de la fonction ft_split.
 */

/**
 * @brief Compte le nombre de mots dans une chaîne de caractères.
 * 
 * La fonction `ft_count_words` compte le nombre de mots dans une chaîne de 
 * caractères, en utilisant un séparateur spécifié.
 * 
 * @param s La chaîne de caractères.
 * @param c Le séparateur.
 * @return Le nombre de mots.
 */
static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief Alloue de la mémoire pour un tableau de chaînes de caractères.
 * 
 * La fonction `ft_allocate_memory` alloue de la mémoire pour un tableau de 
 * chaînes de caractères, en utilisant un nombre spécifié de mots.
 * 
 * @param words Le nombre de mots.
 * @return Un pointeur vers le tableau alloué, ou NULL en cas d'erreur.
 */
static char	**ft_allocate_memory(int words)
{
	char	**tab;
	int		i;

	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		tab[i] = NULL;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/**
 * @brief Copie un mot dans une chaîne de caractères.
 * 
 * La fonction `ft_copy_word` copie un mot dans une chaîne de caractères, en 
 * utilisant un séparateur spécifié.
 * 
 * @param word Le pointeur vers le mot à copier.
 * @param c Le séparateur.
 * @return Le mot copié.
 */
static char	*ft_copy_word(const char *word, char c)
{
	int		i;
	char	*new_word;

	i = 0;
	while (word[i] && word[i] != c)
		i++;
	if (!(new_word = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (word[i] && word[i] != c)
	{
		new_word[i] = word[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

/**
 * @brief Divise une chaîne de caractères en un tableau de chaînes.
 * 
 * La fonction `ft_split` divise une chaîne de caractères en un tableau de 
 * chaînes de caractères, en utilisant un séparateur spécifié.
 * 
 * @param s La chaîne de caractères à diviser.
 * @param c Le séparateur.
 * @return Un pointeur vers le tableau de chaînes de caractères, ou NULL
 * en cas d'erreur.
 */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = ft_allocate_memory(words);
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[j] = ft_copy_word(&s[i], c);
			if (!tab[j])
			{
				ft_free_tab(tab);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (tab);
}

/**
 * @brief Libère la mémoire allouée pour un tableau de chaînes.
 * 
 * La fonction `ft_free_tab` libère la mémoire allouée pour un tableau de 
 * chaînes de caractères.
 * 
 * @param tab Le tableau de chaînes de caractères.
 */
void	ft_free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:10:53 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_strtrim.c
 * @brief Implémentation de la fonction ft_strtrim.
 */

/**
 * @brief Vérifie si un caractère est présent dans une chaîne de caractères.
 * 
 * La fonction `ft_is_in_set` vérifie si un caractère est présent dans une
 * chaîne de caractères.
 * 
 * @param c Le caractère à vérifier.
 * @param set La chaîne de caractères contenant les caractères à rechercher.
 * @return 1 si le caractère est présent, 0 sinon.
 */
static int	ft_is_in_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Supprime les caractères de début et de fin d'une chaîne.
 * 
 * La fonction `ft_strtrim` supprime les caractères de début et de fin d'une 
 * chaîne de caractères, en utilisant un ensemble de caractères spécifié.
 * 
 * @param s1 La chaîne de caractères à tronquer.
 * @param set L'ensemble de caractères à supprimer.
 * @return Un pointeur vers la nouvelle chaîne tronquée, ou NULL en cas 
 * d'erreur.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;
	if (!(result = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	ft_strncpy(result, &s1[start], end - start);
	result[end - start] = '\0';
	return (result);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:12:51 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_substr.c
 * @brief Implémentation de la fonction ft_substr.
 */

/**
 * @brief Extrait une sous-chaîne d'une chaîne de caractères.
 * 
 * La fonction `ft_substr` extrait une sous-chaîne d'une chaîne de caractères,
 * à partir d'un indice donné et avec une longueur spécifiée.
 * 
 * @param s La chaîne de caractères source.
 * @param start L'indice de début de la sous-chaîne.
 * @param len La longueur de la sous-chaîne.
 * @return Un pointeur vers la nouvelle sous-chaîne, ou NULL en cas d'erreur.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:13:21 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_strlcat.c
 * @brief Implémentation de la fonction ft_strlcat.
 */

/**
 * @brief Concatène deux chaînes de caractères avec limitation de taille.
 * 
 * La fonction `ft_strlcat` concatène deux chaînes de caractères, en limitant
 * la taille de la chaîne de destination.
 * 
 * @param dst La chaîne de caractères de destination.
 * @param src La chaîne de caractères source.
 * @param dstsize La taille maximale de la chaîne de destination.
 * @return La longueur totale de la chaîne résultante.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:13:03 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_strlcpy.c
 * @brief Implémentation de la fonction ft_strlcpy.
 */

/**
 * @brief Copie une chaîne de caractères avec limitation de taille.
 * 
 * La fonction `ft_strlcpy` copie une chaîne de caractères dans une autre, en
 * limitant la taille de la chaîne de destination.
 * 
 * @param dst La chaîne de caractères de destination.
 * @param src La chaîne de caractères source.
 * @param dstsize La taille maximale de la chaîne de destination.
 * @return La longueur de la chaîne source.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:10:11 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_memcmp.c
 * @brief Implémentation de la fonction ft_memcmp.
 */

/**
 * @brief Compare deux zones mémoire.
 * 
 * La fonction `ft_memcmp` compare les `n` premiers octets de deux zones mémoire
 * et retourne un entier négatif, zéro ou positif si la première zone mémoire est
 * respectivement inférieure, égale ou supérieure à la deuxième zone mémoire.
 * 
 * @param s1 La première zone mémoire.
 * @param s2 La deuxième zone mémoire.
 * @param n Le nombre d'octets à comparer.
 * @return Un entier négatif, zéro ou positif selon la comparaison des zones mémoire.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:10:24 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_memmove.c
 * @brief Implémentation de la fonction ft_memmove.
 */

/**
 * @brief Copie une zone mémoire vers une autre.
 * 
 * La fonction `ft_memmove` copie `n` octets de la zone mémoire source `src`
 * vers la zone mémoire de destination `dest`. La fonction gère les chevauchements
 * entre les zones mémoire.
 * 
 * @param dest La zone mémoire de destination.
 * @param src La zone mémoire source.
 * @param n Le nombre d'octets à copier.
 * @return La zone mémoire de destination.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*src1;
	size_t	i;

	dst = (char *)dest;
	src1 = (char *)src;
	if (dst == src1 || n == 0)
		return (dest);
	if (src1 < dst)
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = src1[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:10:01 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_memcpy.c
 * @brief Implémentation de la fonction ft_memcpy.
 */

/**
 * @brief Copie une zone mémoire vers une autre.
 * 
 * La fonction `ft_memcpy` copie `n` octets de la zone mémoire source `src`
 * vers la zone mémoire de destination `dest`. La fonction ne gère pas les 
 * chevauchements entre les zones mémoire.
 * 
 * @param dest La zone mémoire de destination.
 * @param src La zone mémoire source.
 * @param n Le nombre d'octets à copier.
 * @return La zone mémoire de destination.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*src1;
	size_t	i;

	dst = (char *)dest;
	src1 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = src1[i];
		i++;
	}
	return (dest);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:10:33 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @file ft_memset.c
 * @brief Implémentation de la fonction ft_memset.
 */

/**
 * @brief Remplit une zone mémoire avec une valeur.
 * 
 * La fonction `ft_memset` remplit `n` octets de la zone mémoire `s`
 * avec la valeur `c`.
 * 
 * @param s La zone mémoire.
 * @param c La valeur à remplir.
 * @param n Le nombre d'octets à remplir.
 * @return La zone mémoire remplie.