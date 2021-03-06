// license:BSD-3-Clause
// copyright-holders:R. Belmont
/*********************************************************************

    a2estd80col.c

    Apple IIe Standard 80 Column Card

*********************************************************************/

#ifndef __A2EAUX_STD80COL__
#define __A2EAUX_STD80COL__

#include "a2eauxslot.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

class a2eaux_std80col_device:
	public device_t,
	public device_a2eauxslot_card_interface
{
public:
	// construction/destruction
	a2eaux_std80col_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
	a2eaux_std80col_device(const machine_config &mconfig, device_type type, const char *name, const char *tag, device_t *owner, uint32_t clock, const char *shortname, const char *source);

protected:
	virtual void device_start() override;
	virtual void device_reset() override;

	virtual uint8_t read_auxram(uint16_t offset) override;
	virtual void write_auxram(uint16_t offset, uint8_t data) override;
	virtual uint8_t *get_vram_ptr() override;
	virtual uint8_t *get_auxbank_ptr() override;
	virtual bool allow_dhr() override { return false; }  // we don't allow DHR

private:
	uint8_t m_ram[2*1024];
};

// device type definition
extern const device_type A2EAUX_STD80COL;

#endif  /* __A2EAUX_STD80COL__ */
