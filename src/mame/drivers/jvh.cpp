// license:BSD-3-Clause
// copyright-holders:Robbbert
/*******************************************************************************

  PINBALL
  JVH : Escape, and Movie Masters

********************************************************************************/
#include "emu.h"
#include "cpu/tms9900/tms9980a.h"
#include "cpu/m6800/m6800.h"
#include "machine/6522via.h"
//#include "machine/74259.h"
//#include "sound/ay8910.h"

class jvh_state : public driver_device
{
public:
	jvh_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
	m_maincpu(*this, "maincpu")
	{ }

	void common(machine_config &config);
	void jvh(machine_config &config);
	void jvh2(machine_config &config);

	void init_jvh();

private:
	void escape_io(address_map &map);
	void jvh_map(address_map &map);
	void jvh_sub_map(address_map &map);
	void movmastr_io(address_map &map);
	// devices
	required_device<cpu_device> m_maincpu;

	// driver_device overrides
	virtual void machine_reset() override;
};



void jvh_state::jvh_map(address_map &map)
{
	map(0x0000, 0x3bff).rom();
	map(0x3c00, 0x3cff).ram();
}

void jvh_state::escape_io(address_map &map)
{
	//map(0x0010, 0x002f).r(FUNC(jvh_state::sw1_r));
	//map(0x0030, 0x005f).r(FUNC(jvh_state::dip_r));
	//map(0x0060, 0x007f).r(FUNC(jvh_state::sw6_r));
	//map(0x0020, 0x002b).w(FUNC(jvh_state::snd_w));
	//map(0x002c, 0x002d).w(FUNC(jvh_state::latch_w));
	//map(0x002e, 0x0033).w(FUNC(jvh_state::out1a_w));
	//map(0x0034, 0x0035).w(FUNC(jvh_state::enable_w));
	//map(0x0036, 0x003f).w(FUNC(jvh_state::out1b_w));
	//map(0x0040, 0x004f).w(FUNC(jvh_state::out2a_w));
	//map(0x0050, 0x005f).w(FUNC(jvh_state::out2b_w));
	//map(0x0060, 0x006f).w(FUNC(jvh_state::out3a_w));
	//map(0x007c, 0x007d).w(FUNC(jvh_state::irq_enable));
	//map(0x007e, 0x007f).w(FUNC(jvh_state::zc_enable));
	//map(0x0080, 0x008f).w(FUNC(jvh_state::digit_w));
	//map(0x0090, 0x0097).w(FUNC(jvh_state::bcd_w));
	//map(0x0098, 0x00a1).w(FUNC(jvh_state::panel_w));
	//map(0x00a2, 0x00ab).w(FUNC(jvh_state::col_w));
	//map(0x00b0, 0x00bf).w(FUNC(jvh_state::out5b_w));
	//map(0x00c0, 0x00cf).w(FUNC(jvh_state::out6a_w));
	//map(0x00d0, 0x00df).w(FUNC(jvh_state::out6b_w));
	//map(0x00e0, 0x00e9).w(FUNC(jvh_state::out7a_w));
	//map(0x00ea, 0x00ff).w(FUNC(jvh_state::sol_w));
}

void jvh_state::movmastr_io(address_map &map)
{
	//map(0x01, 0x02).r(FUNC(jvh_state::sw1_r));
	//map(0x03, 0x05).r(FUNC(jvh_state::dip_r));
	//map(0x08, 0x09).r(FUNC(jvh_state::sw6_r));
	//map(0x00, 0x07).w(FUNC(jvh_state::out0a2_w));
	//map(0x08, 0x0f).w(FUNC(jvh_state::out0b2_w));
	//map(0x10, 0x17).w(FUNC(jvh_state::out1a2_w));
	//map(0x18, 0x1f).w(FUNC(jvh_state::out1b2_w));
	//map(0x20, 0x27).w(FUNC(jvh_state::out2a2_w));
	//map(0x28, 0x2f).w(FUNC(jvh_state::out2b2_w));
	//map(0x30, 0x30).w(FUNC(jvh_state::out3a2_w));
	//map(0x31, 0x36).w(FUNC(jvh_state::snd_w));
	//map(0x37, 0x37).w(FUNC(jvh_state::latch_w));
	//map(0x3e, 0x3e).w(FUNC(jvh_state::irq_enable));
	//map(0x3f, 0x3f).w(FUNC(jvh_state::zc_enable));
	//map(0x40, 0x47).w(FUNC(jvh_state::out4a2_w));
	//map(0x48, 0x4a).w(FUNC(jvh_state::out4b2_w));
	//map(0x4b, 0x4b).w(FUNC(jvh_state::enable_w));
	//map(0x4c, 0x4f).w(FUNC(jvh_state::out4c2_w));
	//map(0x50, 0x55).w(FUNC(jvh_state::col_w));
	//map(0x57, 0x5a).w(FUNC(jvh_state::bcd_w));
	//map(0x5b, 0x5f).w(FUNC(jvh_state::panel_w));
	//map(0x60, 0x67).w(FUNC(jvh_state::digit_w));
	//map(0x68, 0x6f).w(FUNC(jvh_state::out6b2_w));
	//map(0x70, 0x74).w(FUNC(jvh_state::out7a2_w));
	//map(0x75, 0x7f).w(FUNC(jvh_state::sol_w));
}

void jvh_state::jvh_sub_map(address_map &map)
{
	map(0x0000, 0x007f).ram();
	map(0x0080, 0x008f).m("via", FUNC(via6522_device::map));
	map(0xc000, 0xdfff).mirror(0x2000).rom();
}

static INPUT_PORTS_START( jvh )
INPUT_PORTS_END

void jvh_state::machine_reset()
{
}

void jvh_state::init_jvh()
{
}

void jvh_state::common(machine_config &config)
{
	// CPU TMS9980A; no line connections
	TMS9980A(config, m_maincpu, 10000000);
	m_maincpu->set_addrmap(AS_PROGRAM, &jvh_state::jvh_map);

	m6802_cpu_device &soundcpu(M6802(config, "soundcpu", XTAL(4'000'000)));
	soundcpu.set_addrmap(AS_PROGRAM, &jvh_state::jvh_sub_map);

	via6522_device &via(VIA6522(config, "via", XTAL(4'000'000) / 4)); // MC6802 E clock
	via.irq_handler().set_inputline("soundcpu", M6802_IRQ_LINE);
}

void jvh_state::jvh(machine_config &config)
{
	common(config);
	m_maincpu->set_addrmap(AS_IO, &jvh_state::escape_io);
}

void jvh_state::jvh2(machine_config &config)
{
	common(config);
	m_maincpu->set_addrmap(AS_IO, &jvh_state::movmastr_io);
}



/*-------------------------------------------------------------------
/ Escape
/-------------------------------------------------------------------*/
ROM_START(escape)
	ROM_REGION(0x4000, "maincpu", 0)
	ROM_LOAD("cpu_ic1.bin", 0x0000, 0x2000, CRC(fadb8f9a) SHA1(b7e7ea8e33847c14a3414f5e367e304f12c0bc00))
	ROM_LOAD("cpu_ic7.bin", 0x2000, 0x2000, CRC(2f9402b4) SHA1(3d3bae7e4e5ad40e3c8019d55392defdffd21cc4))

	ROM_REGION(0x10000, "soundcpu", 0)
	ROM_LOAD("snd.bin",     0xc000, 0x2000, CRC(2477bbe2) SHA1(f636952822153f43e9d09f8211edde1057249203))
ROM_END

/*-------------------------------------------------------------------
/ Movie Masters
/-------------------------------------------------------------------*/
ROM_START(movmastr)
	ROM_REGION(0x4000, "maincpu", 0)
	ROM_LOAD("mm_ic1.764", 0x0000, 0x2000, CRC(fb59920d) SHA1(05536c4c036a8d73516766e14f4449665b2ec180))
	ROM_LOAD("mm_ic7.764", 0x2000, 0x2000, CRC(9b47af41) SHA1(ae795c22aa437d6c71312d93de8a87f43ee500fb))

	ROM_REGION(0x10000, "soundcpu", 0)
	ROM_LOAD("snd.bin", 0xc000, 0x2000, NO_DUMP)
ROM_END


GAME( 1987, escape,   0, jvh,  jvh, jvh_state, init_jvh, ROT0, "Jac Van Ham (Royal)", "Escape",             MACHINE_IS_SKELETON_MECHANICAL)
GAME( 19??, movmastr, 0, jvh2, jvh, jvh_state, init_jvh, ROT0, "Jac Van Ham (Royal)", "Movie Masters",      MACHINE_IS_SKELETON_MECHANICAL)
