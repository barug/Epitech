/*
** code_dump.c for code_dump in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Nov 25 17:04:13 2014 barthelemy gouby
** Last update Wed Nov 26 16:03:45 2014 barthelemy gouby
*/

int     get_files_list(char *pathname)
{
  DIR           *dirp;
  struct dirent *entry;
  char          *new_pathname;

  if ((dirp = opendir(pathname)) == NULL)
    return (1);
  while ((entry = readdir(dirp)) != NULL)
    {
      if (entry->d_name[0] != '.')
        {
          my_putchar('b');
          new_pathname = add_str_m(pathname, entry->d_name);
          if_l_option(new_pathname);
          my_printf(" %s\n", entry->d_name);
          free(new_pathname);
        }
    }
  closedir(dirp);
  return (0);
}

struct dirent   **make_entry_array(char *pathname)
{
  DIR           *dirp;
  struct dirent *entry;
  struct dirent **entry_array;
  int           i;

  i = 0;
  if ((dirp = opendir(pathname)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      i++;
  closedir(dirp);
  entry_array = malloc((i + 1) * sizeof(entry));
  i = 0;
  if ((dirp = opendir(pathname)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      entry_array[i++] = entry;
  entry_array[i] = NULL;
  return (entry_array);
}

struct dirent **sort_name_entry_array(struct dirent **entry_array)
{
  int           i;
  int           position;
  int           indic;
  struct dirent *buffer;

  i = 0;
  position = 0;
  indic = 1;
  while (entry_array[position] != NULL)
    {
      indic = 0;
      i = 0;
      while (entry_array[i] != NULL && indic != 1)
        {
          if (strcmp(entry_array[position]->d_name,entry_array[i]->d_name) < 0)
            {
              buffer = entry_array[position];
              entry_array[position] = entry_array[i];
              entry_array[i] = buffer;
              indic = 1;
            }
          i++;
        }
      entry_array[i] == NULL ? position++ : 0;
    }
  return (entry_array);
}

struct dirent **sort_time_entry_array(struct dirent **entry_array)
{
  int           i;
  int           position;
  int           indic;
  struct dirent *buffer;

  i = 0;
  position = 0;
  indic = 1;
  while (entry_array[position] != NULL)
    {
      indic = 0;
      i = 0;
      while (entry_array[i] != NULL && indic != 1)
        {
          if (strcmp(entry_array[position]->d_name,entry_array[i]->d_name) < 0)
            {
              buffer = entry_array[position];
              entry_array[position] = entry_array[i];
              entry_array[i] = buffer;
              indic = 1;
            }
          i++;
        }
      entry_array[i] == NULL ? position++ : 0;
    }
  return (entry_array);
}
