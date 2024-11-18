/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:16:11 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 23:33:01 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @file get_next_line_bonus.c
 * @brief Implémentation de la fonction get_next_line_bonus.
 */

/**
 * @brief Duplique une chaîne de caractères jusqu'au caractère de retour chariot.
 *
 * Copie une chaîne de caractères jusqu'à ce qu'elle rencontre le caractère
 * de retour chariot '\n' ou la fin de la chaîne '\0'.
 *
 * @param s La chaîne de caractères à dupliquer.
 * @return La nouvelle chaîne de caractères dupliquée, ou NULL en cas d'erreur.
 */
char	*ft_strdup_until_carriage_return(char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	str = malloc((sizeof(char) * i) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Sous-chaîne modifiée d'une chaîne de caractères.
 * 
 * Extrait une sous-chaîne d'une chaîne de caractères donnée, en commençant
 * à partir d'un index de départ spécifique et en utilisant une longueur
 * donnée. La fonction gère également les cas où le point de départ ou
 * la longueur dépassent la fin de la chaîne.
 * 
 * @param s La chaîne de caractères source.
 * @param start L'index de départ de la sous-chaîne.
 * @param len La longueur de la sous-chaîne.
 * @param i Variable pour suivre la position dans la chaîne (utilisée pour
 *          déterminer la longueur réelle de la chaîne).
 * @return Un pointeur vers la nouvelle sous-chaîne, ou NULL en cas d'erreur.
 */
char	*ft_substr_modif(char const *s, unsigned int start,
						size_t len, unsigned int i)
{
	char			*str;

	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (start + 1 > i)
		return (ft_str((char*)s));
	if (start + len > i)
		len = (len - (len - i) + 1);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	free((char*)s);
	s = NULL;
	return (str);
}

/**
 * @brief Extrait la ligne et le reste d'une chaîne de caractères.
 * 
 * Cette fonction extrait la ligne complète (jusqu'au prochain '\n') et
 * met à jour le reste de la chaîne pour conserver les caractères restants.
 *
 * @param reste Pointeur vers la chaîne de caractères restante.
 * @param line Pointeur vers le pointeur de la ligne extraite.
 * @return Le reste de la chaîne de caractères, ou NULL en cas d'erreur.
 */
char	*ft_reste(char *reste, char **line)
{
	int len;

	len = ft_strlen_modif(reste, 1);
	*line = ft_strdup_until_carriage_return(reste);
	reste = ft_substr_modif(reste, len + 1, ft_strlen_modif(reste, 0), 0);
	return (reste);
}

/**
 * @brief Libère la mémoire allouée à une chaîne de caractères.
 * 
 * Libère la mémoire allouée pour une chaîne de caractères et la met à NULL.
 *
 * @param s Pointeur vers la chaîne de caractères à libérer.
 * @return Le pointeur s après avoir été libéré.
 */
char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

/**
 * @brief Lit une ligne d'un descripteur de fichier.
 * 
 * Lit une ligne complète (jusqu'au prochain '\n') d'un descripteur
 * de fichier donné.
 *
 * @param fd Le descripteur de fichier à lire.
 * @param line Pointeur vers le pointeur de la ligne extraite.
 * @return Le nombre de caractères lus, ou -1 en cas d'erreur.
 */
int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char *reste[1024];
	int			res;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if ((buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	res = 1;
	while ((ft_strchr(reste[fd], '\n') == NULL) && (res != 0))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) < 0)
			ft_free(buf);
		if (res < 0)
			return (-1);
		buf[res] = '\0';
		if (res > 1)
			res = 1;
		reste[fd] = (reste[fd] == NULL)
			? ft_strdup(buf) : ft_strjoin(reste[fd], buf);
	}
	reste[fd] = ft_reste(reste[fd], line);
	reste[fd] = (res == 0) ? ft_free(reste[fd]) : reste[fd];
	ft_free(buf);
	return (res);
}
            

