/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:11:30 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 23:12:37 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
 * @file get_next_line_bonus.h
 * @brief Header file for get_next_line_bonus.
 */

/**
 * @brief Function that reads a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param line A pointer to the address of the line read from the file descriptor.
 * @return 1 if a line was read, 0 if end of file was reached, -1 if an error occurred.
 */
int		get_next_line(int fd, char **line);

/**
 * @brief Duplicates a string.
 *
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated duplicate string.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Calculates the length of a string, ignoring carriage returns.
 *
 * @param s The string to calculate the length of.
 * @param carriage Whether to ignore carriage returns.
 * @return The length of the string, ignoring carriage returns if specified.
 */
int		ft_strlen_modif(const char *s, int carriage);

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * @param s The string to search in.
 * @param c The character to find.
 * @return A pointer to the first occurrence of the character in the string, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Concatenates two strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the newly allocated concatenated string.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Extracts a substring from a string.
 *
 * @param s The string to extract from.
 * @return A pointer to the newly allocated substring.
 */
char	*ft_str(char *s);

#endif
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:19 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/17 14:29:30 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char		**ft_free_tab(char **tab, size_t i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char		*ft_str_to_word(const char *str, char c, size_t *j)
{
	size_t	i;
	size_t	len;
	char	*word;

	len = 0;
	i = *j;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[*j] != c && str[*j])
	{
		word[i++] = str[*j];
		(*j)++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(const char *str, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	nb_words;

	nb_words = ft_count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (str[j] == c && str[j])
			j++;
		if (str[j])
		{
			tab[i] = ft_str_to_word(str, c, &j);
			if (tab[i] == NULL)
				return (ft_free_tab(tab, i));
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
} OUTPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:19 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/17 14:29:30 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/**
 * @file ft_split.c
 * @brief Implémentation de la fonction ft_split.
 */

/**
 * @brief Compte le nombre de mots dans une chaîne de caractères.
 * 
 * @param str La chaîne de caractères à analyser.
 * @param c Le caractère séparateur.
 * @return Le nombre de mots dans la chaîne.
 */
static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief Libère la mémoire allouée pour un tableau de chaînes de caractères.
 * 
 * @param tab Le tableau de chaînes à libérer.
 * @param i L'indice du dernier élément du tableau à libérer.
 * @return NULL.
 */
static char		**ft_free_tab(char **tab, size_t i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

/**
 * @brief Extrait un mot d'une chaîne de caractères.
 * 
 * @param str La chaîne de caractères à analyser.
 * @param c Le caractère séparateur.
 * @param j Pointeur vers l'indice de début du mot dans la chaîne.
 * @return Un pointeur vers le mot extrait, ou NULL en cas d'erreur.
 */
static char		*ft_str_to_word(const char *str, char c, size_t *j)
{
	size_t	i;
	size_t	len;
	char	*word;

	len = 0;
	i = *j;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[*j] != c && str[*j])
	{
		word[i++] = str[*j];
		(*j)++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * @brief Divise une chaîne de caractères en un tableau de mots.
 * 
 * @param str La chaîne de caractères à diviser.
 * @param c Le caractère séparateur.
 * @return Un tableau de mots, ou NULL en cas d'erreur.
 */
char			**ft_split(const char *str, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	nb_words;

	nb_words = ft_count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (str[j] == c && str[j])
			j++;
		if (str[j])
		{
			tab[i] = ft_str_to_word(str, c, &j);
			if (tab[i] == NULL)
				return (ft_free_tab(tab, i));
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
            INPUT #ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

struct s_bin;

typedef struct		s_node
{
	int				value;
	sem_t			*sem_eat;
	pthread_mutex_t	*lock_std;
	pthread_mutex_t	lock;
	pthread_mutex_t	eat;
	int				end;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	long long		start;
	int				count_eat;
	int				nb_eat;
	pthread_t		thread;
	pthread_t		monitor;
	struct s_node	*next;
	char			str[50];
	struct s_bin	*var;
}					t_node;

typedef struct		s_bin
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				nb;
	int				end;
	t_node			*philo;
	int				count_eat;
	sem_t			*sem_forks;
	sem_t			*sem_die;
	sem_t			*sem_eat;
	pthread_mutex_t	lock_std;
	sem_t			*sem_print;
}					t_bin;

void				ft_sleep(int n);
size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char *s, int fd);
void				ft_putlnbr_fd(long long n, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isdigit(int i);
int					ft_atoi(const char *str);
int					ft_arg(t_bin *var, int ac, char **av);
int					ft_create(t_bin *var);
int					ft_clear(t_bin *var, int i, int l);
void				*fn_philo(void *p_data);
void				*fn_monitor_eat(void *p_data);
void				*fn_monitor(void *p_data);
long long			current_timestamp(void);
void				print_value(sem_t *sem_die, int *val);
void				ft_putlnbr_str(long long a, t_node *n);
void				ft_putnbr_str(int a, t_node *n);
void				ft_message(t_node *n, char *str, long long tm,\
unsigned int j);
int					ft_check_arg(int ac, char **av);
int					ft_strisdigit(char *str);
void				ft_message_die(t_node *n, char *str, long long tm,\
unsigned int j);
char				**ft_split(const char *str, char c);
int					ft_go_thread(t_bin *var);
int					ft_check_end(t_bin *var);

#endif OUTPUT /**
 * @file philo_two.h
 * @brief Contient les déclarations pour le projet Philosophes (philo_two).
 */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

/**
 * @struct s_bin
 * @brief Structure contenant les variables globales du programme.
 */
struct s_bin;

/**
 * @struct s_node
 * @brief Structure représentant un philosophe.
 */
typedef struct		s_node
{
	int				value; /**< Valeur du philosophe. */
	sem_t			*sem_eat; /**< Sémaphore pour l'action de manger. */
	pthread_mutex_t	*lock_std; /**< Mutex pour l'affichage standard. */
	pthread_mutex_t	lock; /**< Mutex pour le philosophe. */
	pthread_mutex_t	eat; /**< Mutex pour l'action de manger. */
	int				end; /**< Indicateur de fin du programme. */
	int				tt_die; /**< Temps de mourir. */
	int				tt_eat; /**< Temps pour manger. */
	int				tt_sleep; /**< Temps pour dormir. */
	long long		start; /**< Temps de départ. */
	int				count_eat; /**< Nombre de fois que le philosophe a mangé. */
	int				nb_eat; /**< Nombre de fois que le philosophe doit manger. */
	pthread_t		thread; /**< Thread du philosophe. */
	pthread_t		monitor; /**< Thread de surveillance du philosophe. */
	struct s_node	*next; /**< Pointeur vers le philosophe suivant. */
	char			str[50]; /**< Chaîne de caractères pour l'affichage. */
	struct s_bin	*var; /**< Pointeur vers les variables globales. */
}					t_node;

/**
 * @struct s_bin
 * @brief Structure contenant les variables globales du programme.
 */
typedef struct		s_bin
{
	int				time_to_die; /**< Temps de mourir. */
	int				time_to_eat; /**< Temps pour manger. */
	int				time_to_sleep; /**< Temps pour dormir. */
	int				nb_eat; /**< Nombre de fois que chaque philosophe doit manger. */
	int				nb; /**< Nombre de philosophes. */
	int				end; /**< Indicateur de fin du programme. */
	t_node			*philo; /**< Pointeur vers le premier philosophe. */
	int				count_eat; /**< Nombre total de fois que les philosophes ont mangé. */
	sem_t			*sem_forks; /**< Sémaphore pour les fourchettes. */
	sem_t			*sem_die; /**< Sémaphore pour la mort. */
	sem_t			*sem_eat; /**< Sémaphore pour l'action de manger. */
	pthread_mutex_t	lock_std; /**< Mutex pour l'affichage standard. */
	sem_t			*sem_print; /**< Sémaphore pour l'affichage. */
}					t_bin;

/**
 * @brief Met en pause le programme pendant un temps donné.
 * 
 * @param n Le temps de pause en millisecondes.
 */
void				ft_sleep(int n);

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 * 
 * @param str La chaîne de caractères.
 * @return La longueur de la chaîne de caractères.
 */
size_t				ft_strlen(const char *str);

/**
 * @brief Affiche une chaîne de caractères sur la sortie standard.
 * 
 * @param s La chaîne de caractères à afficher.
 * @param fd Le descripteur de fichier de la sortie standard (généralement 1).
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Affiche un nombre long long sur la sortie standard, suivi d'un retour à la ligne.
 * 
 * @param n Le nombre à afficher.
 * @param fd Le descripteur de fichier de la sortie standard (généralement 1).
 */
void				ft_putlnbr_fd(long long n, int fd);

/**
 * @brief Affiche un nombre entier sur la sortie standard.
 * 
 * @param n Le nombre à afficher.
 * @param fd Le descripteur de fichier de la sortie standard (généralement 1).
 */
void				ft_putnbr_fd(int n, int fd);

/**
 * @brief Vérifie si un caractère est un chiffre.
 * 
 * @param i Le caractère à vérifier.
 * @return 1 si le caractère est un chiffre, 0 sinon.
 */
int					ft_isdigit(int i);

/**
 * @brief Convertit une chaîne de caractères en entier.
 * 
 * @param str La chaîne de caractères à convertir.
 * @return L'entier converti, ou 0 si la conversion échoue.
 */
int					ft_atoi(const char *str);

/**
 * @brief Analyse les arguments du programme et initialise les variables globales.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param ac Nombre d'arguments.
 * @param av Tableau d'arguments.
 * @return 0 si l'analyse se déroule correctement, -1 sinon.
 */
int					ft_arg(t_bin *var, int ac, char **av);

/**
 * @brief Crée les threads des philosophes.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 0 si la création des threads se déroule correctement, -1 sinon.
 */
int					ft_create(t_bin *var);

/**
 * @brief Nettoie les ressources allouées pour les philosophes.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param i Indice du premier philosophe.
 * @param l Indice du dernier philosophe.
 * @return 0.
 */
int					ft_clear(t_bin *var, int i, int l);

/**
 * @brief Fonction exécutée par chaque thread de philosophe.
 * 
 * @param p_data Pointeur vers les données du philosophe.
 * @return NULL.
 */
void				*fn_philo(void *p_data);

/**
 * @brief Fonction de surveillance de l'état de santé d'un philosophe.
 * 
 * @param p_data Pointeur vers les données du philosophe.
 * @return NULL.
 */
void				*fn_monitor_eat(void *p_data);

/**
 * @brief Fonction de surveillance de l'état de santé des philosophes.
 * 
 * @param p_data Pointeur vers les données du programme.
 * @return NULL.
 */
void				*fn_monitor(void *p_data);

/**
 * @brief Retourne le timestamp actuel en millisecondes.
 * 
 * @return Le timestamp actuel.
 */
long long			current_timestamp(void);

/**
 * @brief Affiche la valeur d'un semaphore.
 * 
 * @param sem_die Pointeur vers le semaphore.
 * @param val Pointeur vers la variable qui contiendra la valeur du semaphore.
 */
void				print_value(sem_t *sem_die, int *val);

/**
 * @brief Affiche un message formaté avec le timestamp et l'identifiant du philosophe.
 * 
 * @param a Le timestamp.
 * @param n Pointeur vers le philosophe.
 */
void				ft_putlnbr_str(long long a, t_node *n);

/**
 * @brief Affiche un message formaté avec l'identifiant du philosophe.
 * 
 * @param a L'identifiant du philosophe.
 * @param n Pointeur vers le philosophe.
 */
void				ft_putnbr_str(int a, t_node *n);

/**
 * @brief Affiche un message formaté pour un philosophe.
 * 
 * @param n Pointeur vers le philosophe.
 * @param str Le message à afficher.
 * @param tm Le timestamp.
 * @param j L'identifiant du philosophe.
 */
void				ft_message(t_node *n, char *str, long long tm,\
unsigned int j);

/**
 * @brief Vérifie les arguments du programme.
 * 
 * @param ac Nombre d'arguments.
 * @param av Tableau d'arguments.
 * @return 0 si les arguments sont valides, -1 sinon.
 */
int					ft_check_arg(int ac, char **av);

/**
 * @brief Vérifie si une chaîne de caractères ne contient que des chiffres.
 * 
 * @param str La chaîne de caractères à vérifier.
 * @return 1 si la chaîne ne contient que des chiffres, 0 sinon.
 */
int					ft_strisdigit(char *str);

/**
 * @brief Affiche un message d'erreur formaté pour un philosophe et termine le programme.
 * 
 * @param n Pointeur vers le philosophe.
 * @param str Le message d'erreur à afficher.
 * @param tm Le timestamp.
 * @param j L'identifiant du philosophe.
 */
void				ft_message_die(t_node *n, char *str, long long tm,\
unsigned int j);

/**
 * @brief Divise une chaîne de caractères en un tableau de mots.
 * 
 * @param str La chaîne de caractères à diviser.
 * @param c Le caractère séparateur.
 * @return Un tableau de mots, ou NULL en cas d'erreur.
 */
char				**ft_split(const char *str, char c);

/**
 * @brief Lance les threads des philosophes et de surveillance.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 0 si le lancement des threads se déroule correctement, -1 sinon.
 */
int					ft_go_thread(t_bin *var);

/**
 * @brief Vérifie si la condition de fin du programme est remplie.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 1 si la condition de fin est remplie, 0 sinon.
 */
int					ft_check_end(t_bin *var);

#endif
            INPUT #include "philo_two.h"

int			ft_clear(t_bin *var, int i, int l)
{
	int j;

	j = 1;
	while (j < i + 1)
	{
		pthread_mutex_destroy(&(var->philo[i].lock));
		if (l == 0 && j == i)
			break ;
		pthread_mutex_destroy(&(var->philo[i].eat));
		j++;
	}
	pthread_mutex_destroy(&(var->lock_std));
	free(var->philo);
	return (1);
}

static int	ft_create_philo(t_bin *var, int i)
{
	while (i < var->nb + 1)
	{
		if (i == var->nb)
			var->philo[i].next = &(var->philo[1]);
		else
			var->philo[i].next = &(var->philo[i + 1]);
		var->philo[i].value = i;
		var->philo[i].tt_die = var->time_to_die;
		var->philo[i].tt_eat = var->time_to_eat;
		var->philo[i].tt_sleep = var->time_to_sleep;
		var->philo[i].count_eat = 0;
		var->philo[i].end = 0;
		var->philo[i].nb_eat = var->nb_eat;
		var->philo[i].str[0] = '\0';
		var->philo[i].var = var;
		var->philo[i].lock_std = &(var->lock_std);
		if (pthread_mutex_init(&(var->philo[i].lock), NULL) != 0)
			return ((!(ft_clear(var, i, 0))));
		if (pthread_mutex_init(&(var->philo[i].eat), NULL) != 0)
			return ((!(ft_clear(var, i, 1))));
		i++;
	}
	return (0);
}

int			ft_create(t_bin *var)
{
	if (pthread_mutex_init(&(var->lock_std), NULL) != 0)
		return (1);
	if (!(var->philo = malloc((var->nb + 1) * sizeof(t_node))))
	{
		pthread_mutex_destroy(&(var->lock_std));
		return (1);
	}
	if (ft_create_philo(var, 1))
		return (1);
	return (0);
} OUTPUT /**
 * @file struct.c
 * @brief Gestion des structures et des mutex pour les philosophes.
 * 
 * Ce fichier contient les fonctions nécessaires pour créer, initialiser
 * et nettoyer les structures utilisées dans le programme, notamment
 * les philosophes et leurs mutex.
 */

#include "philo_two.h"

/**
 * @brief Libère la mémoire et détruit les mutex.
 * 
 * Cette fonction détruit les mutex associés à chaque philosophe et
 * libère la mémoire allouée à la structure `philo`. Elle détruit également
 * le mutex global `lock_std`.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param i Indice du premier philosophe.
 * @param l Indice du dernier philosophe (0 si c'est le dernier, sinon 1).
 * @return Toujours retourne 1 (indique que l'opération a été effectuée).
 */
int ft_clear(t_bin *var, int i, int l)
{
    int j;

    j = 1;
    while (j < i + 1)
    {
        pthread_mutex_destroy(&(var->philo[i].lock)); /**< Destruction du mutex de verrouillage. */
        if (l == 0 && j == i)
            break;
        pthread_mutex_destroy(&(var->philo[i].eat)); /**< Destruction du mutex de temps de repas. */
        j++;
    }
    pthread_mutex_destroy(&(var->lock_std)); /**< Destruction du mutex global. */
    free(var->philo); /**< Libération de la mémoire allouée aux philosophes. */
    return (1);
}

/**
 * @brief Crée et initialise les structures des philosophes.
 * 
 * Cette fonction configure les structures de chaque philosophe, lie les mutex,
 * et initialise leurs valeurs par défaut. Chaque philosophe est relié
 * à un suivant pour former une liste circulaire.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param i Indice du premier philosophe.
 * @return Retourne 0 si la création est réussie, sinon une valeur différente de 0.
 */
static int ft_create_philo(t_bin *var, int i)
{
    while (i < var->nb + 1)
    {
        if (i == var->nb)
            var->philo[i].next = &(var->philo[1]); /**< Liaison au premier philosophe (liste circulaire). */
        else
            var->philo[i].next = &(var->philo[i + 1]); /**< Liaison au philosophe suivant. */

        var->philo[i].value = i; /**< Affectation de l'identifiant du philosophe. */
        var->philo[i].tt_die = var->time_to_die; /**< Temps avant de mourir sans manger. */
        var->philo[i].tt_eat = var->time_to_eat; /**< Temps nécessaire pour manger. */
        var->philo[i].tt_sleep = var->time_to_sleep; /**< Temps nécessaire pour dormir. */
        var->philo[i].count_eat = 0; /**< Compteur initialisé à 0. */
        var->philo[i].end = 0; /**< Indicateur de fin initialisé à 0. */
        var->philo[i].nb_eat = var->nb_eat; /**< Nombre de repas nécessaires. */
        var->philo[i].str[0] = '\0'; /**< Chaîne initialisée à vide. */
        var->philo[i].var = var; /**< Pointeur vers la structure globale. */
        var->philo[i].lock_std = &(var->lock_std); /**< Pointeur vers le mutex global. */

        if (pthread_mutex_init(&(var->philo[i].lock), NULL) != 0) /**< Initialisation du mutex de verrouillage. */
            return ((!(ft_clear(var, i, 0))));
        if (pthread_mutex_init(&(var->philo[i].eat), NULL) != 0) /**< Initialisation du mutex de repas. */
            return ((!(ft_clear(var, i, 1))));
        i++;
    }
    return (0);
}

/**
 * @brief Crée et initialise les structures principales du programme.
 * 
 * Cette fonction alloue la mémoire nécessaire pour les philosophes et
 * initialise les mutex globaux ainsi que les structures individuelles.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return Retourne 0 si la création est réussie, sinon 1.
 */
int ft_create(t_bin *var)
{
    if (pthread_mutex_init(&(var->lock_std), NULL) != 0) /**< Initialisation du mutex global. */
        return (1);
    if (!(var->philo = malloc((var->nb + 1) * sizeof(t_node)))) /**< Allocation mémoire pour les philosophes. */
    {
        pthread_mutex_destroy(&(var->lock_std)); /**< Destruction du mutex global en cas d'échec. */
        return (1);
    }
    if (ft_create_philo(var, 1)) /**< Appel de la fonction pour initialiser les philosophes. */
        return (1);
    return (0);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:34:16 by rkhelif           #+#    #+#             */
/*   Updated: 2021/03/19 16:13:46 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_philo_bonus(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->nb_philo)
	{
		philo->philo[i].pid = fork();
		if (philo->philo[i].pid == 0)
		{
			philo->philo[i].start = current_timestamp();
			ft_start_philo(&philo->philo[i]);
			break ;
		}
		i++;
	}
	if (i == philo->nb_philo)
		ft_check_end(philo);
	ft_wait_philo(philo);
}

static void	ft_init_philo(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->nb_philo)
	{
		philo->philo[i].id = i + 1;
		philo->philo[i].eat_count = 0;
		philo->philo[i].last_meal = 0;
		philo->philo[i].end = 0;
		i++;
	}
}

static int	ft_init_sem(t_philo *philo