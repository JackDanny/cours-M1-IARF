function ZCR_res= ZCR_result(S,W,P)
% S signal
% W fenetre
% P le pas


ZCR_res = [];
for x=1:P:(length(S)-W+1)
ZCR_res=[ZCR_res , ZCR_win(S(x:x+W-1))];
end

end
