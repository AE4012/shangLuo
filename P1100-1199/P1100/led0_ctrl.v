module led_ctrl0(
    input  wire Clk,
    input  wire Reset_n,
    output reg  Led
);
    reg [25:0] counter;

    // 50MHz -> 1s = 50_000_000 ticks, 0.25s = 12_500_000 ticks
    localparam integer PERIOD_TICKS = 50_000_000;
    localparam integer HIGH_TICKS   = 12_500_000;

    always @(posedge Clk or negedge Reset_n) begin
        if (!Reset_n)
            counter <= 0;
        else if (counter == PERIOD_TICKS-1)
            counter <= 0;
        else
            counter <= counter + 1'b1;
    end

    always @(posedge Clk or negedge Reset_n) begin
        if (!Reset_n)
            Led <= 1'b0;
        else if (counter == 0)
            Led <= 1'b1;
        else if (counter == HIGH_TICKS-1)
            Led <= 1'b0;
    end

endmodule
