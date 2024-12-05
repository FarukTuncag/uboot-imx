/*
 * (C) Copyright 2002
 * Kyle Harris, Nexus Technologies, Inc. kharris@nexus-tech.net
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <asm/arch/ixp425.h>
#include <common.h>

/* ------------------------------------------------------------------------- */


/* local prototypes */


/*
 * Miscelaneous platform dependent initialisations
 */

/**********************************************************/

int board_post_init (void)
{
	return (0);
}

/**********************************************************/

int board_init (void)
{
	DECLARE_GLOBAL_DATA_PTR;

	/* arch number of IXDP */
	gd->bd->bi_arch_number = MACH_TYPE_IXDP425;

	/* adress of boot parameters */
	gd->bd->bi_boot_params = 0x00000100;

	return 0;
}

/**********************************************************/

int dram_init (void)
{
	DECLARE_GLOBAL_DATA_PTR;

	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size  = PHYS_SDRAM_1_SIZE;

	return (0);
}

/**********************************************************/

extern struct pci_controller hose;

void pci_init_board(void)
{
	extern void pci_ixp_init (struct pci_controller *hose);

	pci_ixp_init(&hose);
}
