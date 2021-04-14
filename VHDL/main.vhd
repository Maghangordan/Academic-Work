library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity main is
    Port ( Hturn : in  STD_LOGIC;
           Lturn : in  STD_LOGIC;
           clock : in  STD_LOGIC;
           Warning : in  STD_LOGIC;
           Brake : in  STD_LOGIC;
           Hlight : out  STD_LOGIC_VECTOR(0 to 2):="000";
           Llight : out  STD_LOGIC_VECTOR(0 to 2):="000");
end main;
-- Tillstånd:
--0.     Lampor av (lamporav)
--1.     Bromsar   (brake)
--2.     Varning   (varning) -> lamporav
--3.  1. Svänger höger (h1) -> h1
--4.  2. Svänger höger (h2) -> h3
--5.  3. Svänger höger (h3) -> h4
--6.  4. Svänger höger reset (h4) -> h1
--7.  1. Svänger vänster (v1) -> v2
--8.  2. Svänger vänster (v2) -> v3
--9.  3. Svänger vänster (v3) -> v4
--10. 3. Svänger vänster reset (v4)->  v1
--11. 1. Högersväng med broms (hb1) -> hb2
--12. 2. Högersväng med broms (hb2) -> hb3
--13. 3. Högersväng med broms (hb3) -> hb4
--14. 4. Högersväng med broms reset (hb4) -> hb1
--15  1. Vänstersväng med broms (vb1) -> vb2
--16  2. Vänstersväng med broms (vb2) -> vb3
--17  3. Vänstersväng med broms (vb3) -> vb4
--18  4. Vänstersväng med broms (vb4) -> vb1

architecture Behavioral of main is
type states is (lamporav, varning, bromsar, h1, h2, h3,h4, v1, v2, v3, v4, hb1, hb2, hb3, hb4, vb1, vb2, vb3, vb4);
signal curr_state, next_state : states;
begin
process(clock)
begin
	curr_state<=next_state;
end process;

process(curr_state,Brake, Hturn, Lturn, Warning)
begin
	case curr_state is
	when lamporav =>
		if(Brake = '1') and not(Hturn = '1') and not(Lturn = '1')then --1. Bromsar
			next_state<=bromsar;
		elsif(Brake = '1') and (Hturn = '1') then --9.1 Högersväng med broms
			next_state<=hb1;
		elsif(Brake = '1') and (Lturn = '1') then --13.1 Vänstersväng med broms
			next_state<=vb1;
		elsif(Warning = '1') then --2. Varning
			next_state<=varning;
		elsif(Hturn = '1') then --3.1 Svänger höger
			next_state<=h1;
		elsif(Lturn = '1') then
			next_state<=v1;
		else
			next_state<=lamporav;
		end if;
	-----------------------------
	when bromsar =>
		if(Brake = '1') and not(Hturn = '1') and not(Lturn = '1') then
			next_state<=bromsar;
		elsif(Brake = '1') and (Hturn = '1') then
			next_state<=hb1;
		elsif(Brake = '1') and (Lturn = '1') then
			next_state<=vb1;	
		else
			next_state<=lamporav;
		end if;
	-----------------------------
	when varning =>
		if(Warning = '1') then
			next_state<=lamporav;
		else
			next_state<=lamporav;
		end if;
	-----------------------------
	when h1 =>
		if(Hturn = '1') then
			next_state<=h2;
		else
			next_state<=lamporav;
		end if;
	when h2 =>
		if(Hturn = '1') then
			next_state<=h3;
		else
			next_state<=lamporav;
		end if;
	when h3 =>
		if(Hturn = '1') then
			next_state<=h4;
		else
			next_state<=lamporav;
		end if;
	when h4 =>
		if(Hturn = '1') then
			next_state<=h1;
		else
			next_state<=lamporav;
		end if;
	-----------------------------
	when v1 =>
		if(Lturn = '1') then
			next_state<=v2;
		else
			next_state<=lamporav;
		end if;
	when v2 =>
		if(Lturn = '1') then
			next_state<=v3;
		else
			next_state<=lamporav;
		end if;
	when v3 =>
		if(Lturn = '1') then
			next_state<=v4;
		else
			next_state<=lamporav;
		end if;
	when v4 =>
		if(Lturn = '1') then
			next_state<=v1;
		else
			next_state<=lamporav;
		end if;
	-----------------------------	
	when hb1 =>
		if(Brake = '1') and (Hturn = '1') then
			next_state<=hb2;
		elsif(Brake = '1') and not(Hturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	when hb2 =>
		if(Brake = '1') and (Hturn = '1') then
			next_state<=hb3;
		elsif(Brake = '1') and not(Hturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	when hb3 =>
		if(Brake = '1') and (Hturn = '1') then
			next_state<=hb4;
		elsif(Brake = '1') and not(Hturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	when hb4 =>
		if(Brake = '1') and (Hturn = '1') then
			next_state<=hb1;
		elsif(Brake = '1') and not(Hturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	-----------------------------
	when vb1 =>
		if(Brake = '1') and (Lturn = '1') then
			next_state<=vb2;
		elsif(Brake = '1') and not(Lturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	when vb2 =>
		if(Brake = '1') and (Lturn = '1') then
			next_state<=vb3;
		elsif(Brake = '1') and not(Lturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	when vb3 =>
		if(Brake = '1') and (Lturn = '1') then
			next_state<=vb4;
		elsif(Brake = '1') and not(Lturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	when vb4 =>
		if(Brake = '1') and (Lturn = '1') then
			next_state<=vb1;
		elsif(Brake = '1') and not(Lturn = '1') then
			next_state<=bromsar;
		else
			next_state<=lamporav;
		end if;
	-----------------------------	
	when others => next_state<=lamporav;
	end case;
end process;
process(curr_state)
begin
	case curr_state is
	--------------------------------------------------  1. Bromsar
	when bromsar => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1'; report "bromsar"; 	
	--------------------------------------------------  2. Varning
	when varning => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='1'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='1';  report "varning";
	--------------------------------------------------  3. 1. Svänger höger
	when h1 => Hlight(2)<='1'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0'; report "h1";
   --------------------------------------------------  4. 2. Svänger höger
	when h2 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='0'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0'; report "h2";
	--------------------------------------------------  5. 3. Svänger höger
	when h3 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0';  report "h3";
	--------------------------------------------------  5. 4. Svänger höger reset
	when h4 => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0';  report "h4";
	--------------------------------------------------  6. 1. Svänger vänster
	when v1 => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='1'; Llight(1)<='0'; Llight(0)<='0'; report "v1";
	--------------------------------------------------  7. 2. Svänger vänster
	when v2 => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='0'; report "v2";
	--------------------------------------------------  8. 3. Svänger vänster
	when v3 => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1'; report "v3";
	--------------------------------------------------  9. 4. Svänger vänster reset
	when v4 => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0';  report "v4";
	-------------------------------------------------- 10. 1. Högersväng med broms
	when hb1 => Hlight(2)<='1'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1'; report "hb1";
	-------------------------------------------------- 11. 2. Högersväng med broms
	when hb2 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='0'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1'; report "hb2";
	-------------------------------------------------- 12. 3. Högersväng med broms
	when hb3 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1';  report "hb3";
	-------------------------------------------------- 13. 4. Högersväng med broms reset
	when hb4 => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1';  report "hb4";
	-------------------------------------------------- 14. 1. Vänstersväng med broms
	when vb1 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='1'; Llight(1)<='0'; Llight(0)<='0'; report "vb1";
	-------------------------------------------------- 15. 2. Vänstersväng med broms
	when vb2 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='0'; report "vb2";
	-------------------------------------------------- 16. 3. Vänstersväng med broms
	when vb3 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='1'; Llight(1)<='1'; Llight(0)<='1'; report "vb3";
	-------------------------------------------------- 17. 4. Vänstersväng med broms reset
	when vb4 => Hlight(2)<='1'; Hlight(1)<='1'; Hlight(0)<='1'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0';  report "vb4";
	--------------------------------------------------
	when lamporav => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0'; report "lamporav";
	--------------------------------------------------
	when others => Hlight(2)<='0'; Hlight(1)<='0'; Hlight(0)<='0'; Llight(2)<='0'; Llight(1)<='0'; Llight(0)<='0'; 
	end case;
end process;

	
end Behavioral;
