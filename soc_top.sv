module soc_top(

      ///////// CLOCK /////////
      input              CLOCK2_50,
      input              CLOCK3_50,
      input              CLOCK4_50,
      input              CLOCK_50,

      ///////// KEY /////////
      input    [ 3: 0]   KEY,

      ///////// SW /////////
      input    [ 9: 0]   SW,

      ///////// LED /////////
      output   [ 9: 0]   LEDR,

      ///////// Seg7 /////////
      output   [ 6: 0]   HEX0,
      output   [ 6: 0]   HEX1,
      output   [ 6: 0]   HEX2,
      output   [ 6: 0]   HEX3,
      output   [ 6: 0]   HEX4,
      output   [ 6: 0]   HEX5,

      ///////// GPIO /////////
      inout    [35: 0]   GPIO

);

logic [23:0] pio_7_seg;

assign pio_7_seg = 24'hDABEEF;

seven_segment_driver seg0(.data_in(pio_7_seg[3:0]), .data_out(HEX0));
seven_segment_driver seg1(.data_in(pio_7_seg[7:4]), .data_out(HEX1));
seven_segment_driver seg2(.data_in(pio_7_seg[11:8]), .data_out(HEX2));
seven_segment_driver seg3(.data_in(pio_7_seg[15:12]), .data_out(HEX3));
seven_segment_driver seg4(.data_in(pio_7_seg[19:16]), .data_out(HEX4));
seven_segment_driver seg5(.data_in(pio_7_seg[23:20]), .data_out(HEX5));

//=======================================================
//  REG/WIRE declarations
//=======================================================

custom_soc soc(
	.clk_clk(CLOCK_50),
	.reset_reset_n(SW[0]),
	//.serial_modem_cts_pad_i
	//.serial_modem_dcd_pad_i
	//.serial_modem_dsr_pad_i
	//.serial_modem_dtr_pad_o
	//.serial_modem_ri_pad_i
	//.serial_modem_rts_pad_o
	.serial_modem_srx_pad_i(GPIO[0]),
	.serial_modem_stx_pad_o(GPIO[1])
);

//=======================================================
//  Structural coding
//=======================================================




endmodule