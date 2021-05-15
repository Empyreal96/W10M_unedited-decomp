// ExpInitializeBootEnvironment 
 
int __fastcall ExpInitializeBootEnvironment(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r2

  if ( (*(_DWORD *)(a1 + 144) & 1) != 0 )
    v2 = 2;
  else
    v2 = 1;
  dword_61A1F0 = v2;
  result = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 88);
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 92);
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 96);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 100);
  ExpBootEnvironmentInformation = result;
  unk_61A1E4 = v4;
  unk_61A1E8 = v5;
  unk_61A1EC = v6;
  v7 = *(_DWORD *)(a1 + 132);
  dword_61A1F8 = *(_DWORD *)(v7 + 2160);
  dword_61A1FC = *(_DWORD *)(v7 + 2164);
  return result;
}
