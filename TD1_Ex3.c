
char typeLu = type(fiche[i,j]->name);

switch (typeLu)
{
case 0:
	f_0(data);
	break;
case 1:
	f_1(data);
	break;
case 2:
	f_2(data);
	break;
case 5:
	f_5(data);
	break;
default:
	f_all(data);
	break;
}
