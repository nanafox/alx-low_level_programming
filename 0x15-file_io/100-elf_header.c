#include "main.h"

/**
 * main - prints the ELF header
 * @argc: argument counter
 * @argv: command line arguments (expect name of ELF file)
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int elf_fd, n_read;

	if (argc != 2)
		print_usage();
	elf_fd = open(argv[1], O_RDONLY);
	if (elf_fd == -1)
	{
		print_read_fail(argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(elf_fd);
		print_read_fail(argv[1]);
		exit(98);
	}
	n_read = read(elf_fd, header, sizeof(Elf64_Ehdr));
	if (n_read == -1)
	{
		free(header);
		close_elf(elf_fd);
		dprintf(STDERR_FILENO, "Error: [%s]: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	handle_magic(header->e_ident);
	handle_class(header->e_ident);
	handle_data(header->e_ident);
	handle_version(header->e_ident);
	handle_osabi(header->e_ident);
	handle_abi(header->e_ident);
	handle_type(header->e_type, header->e_ident);
	handle_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(elf_fd);
	return (0);
}

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (is_invalid_elf(e_ident[index]))
		{
			dprintf(STDERR_FILENO,
					"Error: Not an ELF file - it has the wrong magic bytes at the start\n");
			exit(98);
		}
	}
}

/**
 * handle_magic - prints the magic numbers of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * handle_class - prints the class of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * handle_data - prints the data of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * handle_version - prints the version of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * handle_osabi - prints the OS/ABI of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * handle_abi - prints the ABI version of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * handle_type - prints the type of an ELF header
 * @e_type: the type of ELF
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * handle_entry - prints the entry point of an ELF header
 * @e_entry: the address of the ELF's entry point
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void handle_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an ELF file
 * @elf_fd: the file descriptor of the ELF file
 */
void close_elf(int elf_fd)
{
	if (close(elf_fd) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf_fd);

		exit(98);
	}
}

/**
 * print_usage - prints the usage and exit with code 98
 */
void print_usage(void)
{
	dprintf(2, "Usage: elf_header elf_filename\n");
	exit(98);
}
