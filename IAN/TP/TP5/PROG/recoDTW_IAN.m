% Paramétrisation

ref_alpha = extractionCoeffCepstraux('../references/alpha.wav');
ref_bravo = extractionCoeffCepstraux('../references/bravo.wav');
ref_charlie = extractionCoeffCepstraux('../references/charlie.wav');
ref_delta = extractionCoeffCepstraux('../references/delta.wav');
ref_echo = extractionCoeffCepstraux('../references/echo.wav');
ref_foxtrott = extractionCoeffCepstraux('../references/foxtrott.wav');
ref_golf = extractionCoeffCepstraux('../references/golf.wav');
ref_hotel = extractionCoeffCepstraux('../references/hotel.wav');
ref_india = extractionCoeffCepstraux('../references/india.wav');
ref_juliett = extractionCoeffCepstraux('../references/juliett.wav');
ref_kilo = extractionCoeffCepstraux('../references/kilo.wav');
ref_lima = extractionCoeffCepstraux('../references/lima.wav');
ref_mike = extractionCoeffCepstraux('../references/mike.wav');

%%

test_alpha = extractionCoeffCepstraux('../mots_inconnus/alpha.wav');
test_bravo = extractionCoeffCepstraux('../mots_inconnus/bravo.wav');
test_charlie = extractionCoeffCepstraux('../mots_inconnus/charlie.wav');
test_delta = extractionCoeffCepstraux('../mots_inconnus/delta.wav');
test_echo = extractionCoeffCepstraux('../mots_inconnus/echo.wav');
test_foxtrott = extractionCoeffCepstraux('../mots_inconnus/foxtrott.wav');
test_golf = extractionCoeffCepstraux('../mots_inconnus/golf.wav');
test_hotel = extractionCoeffCepstraux('../mots_inconnus/hotel.wav');
test_india = extractionCoeffCepstraux('../mots_inconnus/india.wav');
test_juliett = extractionCoeffCepstraux('../mots_inconnus/juliett.wav');
test_kilo = extractionCoeffCepstraux('../mots_inconnus/kilo.wav');
test_lima = extractionCoeffCepstraux('../mots_inconnus/lima.wav');
test_mike = extractionCoeffCepstraux('../mots_inconnus/mike.wav');


%%
close all;


y= {test_alpha; test_bravo ; test_charlie; test_delta ;test_echo ;test_foxtrott; test_golf; test_hotel; test_india ; test_juliett; test_kilo; test_lima; test_mike};
nom = {'alpha'; 'bravo'; 'charlie';  'delta'; 'echo'; 'foxtrott'; 'golf';'hotel'; 'india'; 'juliett'; 'kilo' ; 'lima'; 'mike'};
matriceCoutTotal = [];
for i =1 : length(y)
    
    x= cell2mat(y(i));
    [chemin dynamicT coutTotal,ens] = DTW_IAN(x, ref_alpha);
    matriceCoutTotal(i,1) = coutTotal;

      
    %figure;
    %imagesc(cell2mat(ens)), xlabel('Test'), ylabel('Ref')
    %nomFig= [ 'test: ' nom{i} ' ref: alpha'];
    %figure('Name',nomFig);
    %imagesc(chemin), xlabel('Test'), ylabel('Ref')
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_bravo);
    matriceCoutTotal(i,2) = coutTotal;

    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_charlie);
    matriceCoutTotal(i,3) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_delta);
    matriceCoutTotal(i,4) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_echo);
    matriceCoutTotal(i,5) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_foxtrott);
    matriceCoutTotal(i,6) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_golf);
    matriceCoutTotal(i,7) = coutTotal;
    

    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_hotel);
    matriceCoutTotal(i,8) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_india);
    matriceCoutTotal(i,9) = coutTotal;
    
    nomFig= [ 'test: ' nom{i} ' ref: india'];
    figure('Name',nomFig);
    imagesc(chemin), xlabel('Test'), ylabel('Ref')

    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_juliett);
    matriceCoutTotal(i,10) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_kilo);
    matriceCoutTotal(i,11) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_lima);
    matriceCoutTotal(i,12) = coutTotal;
    
    [chemin dynamicT coutTotal] = DTW_IAN(x, ref_mike);
    matriceCoutTotal(i,13) = coutTotal;



    [dist,mot]=decision(matriceCoutTotal(i,:),nom);

    phrase=['mot ' nom{i} ' reconnu comme ' mot{1} ' avec distance de ' num2str(dist) ];
    fprintf ('\n');
    
    disp(phrase)
     %matriceCoutTotal(i,:);

end 
for i=1 : length(y)
    figure('Name',nom{i},'NumberTitle','off')
    bar(matriceCoutTotal(i,:))
    title(nom{i})
    set(gca,'XTick',[1 2 3 4 5 6 7 8 9 10 11 12 13])
    set(gca,'XTickLabel',{'alpha' , 'bravo' ,'charlie',  'delta' ,'echo' ,'foxtrott' ,'golf' ,'hotel', 'india', 'juliett' ,'kilo' ,'lima' , 'mike'})
end













