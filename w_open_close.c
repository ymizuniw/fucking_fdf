/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_open_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 21:13:07 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	wopen(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		perror_exit("open");
	return (fd);
}

void	wclose(int fd)
{
	if (close(fd) < 0)
		perror_exit("close");
}
