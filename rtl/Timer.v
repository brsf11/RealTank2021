module Timer #(parameter hiFq = 0) (input wire        clk,rst_n,
                                    output wire[31:0] HRDATA,
                                    output wire       TimerIRQ);

    localparam Count_30 = 21'd1_666_666;
    localparam Count_60 =   21'd833_332;
    reg[20:0] count;
    reg[5:0]  fpsCount;
    wire[20:0] count_num;

    always @(posedge clk) begin
        if(!rst_n)begin
            count <= 21'd0;
        end
        else begin
            if(count == count_num)begin
                count <= 21'd0;
            end
            else begin
                count <= count + 1'b1;
            end
        end
    end

    always @(posedge clk) begin
        if(!rst_n)begin
            fpsCount <= 6'd0;
        end
        else begin
            if(fpsCount == (hiFq?6'd59:6'd29))begin
                fpsCount <= 6'd0;
            end
            else if(count == count_num)begin
                fpsCount <= fpsCount + 1'b1;
            end
        end
    end

    assign count_num = hiFq?Count_60:Count_30;
    assign HRDATA    = {26'b0,fpsCount};
    assign TimerIRQ  = count == count_num;

endmodule