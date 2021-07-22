/// <summary>
/// @NoUnitTest
/// �g�ݍ��킹bit���\�����l���擾����B
/// </summary>
/// <return>
/// �O�̌��ʂ����̈����ɑ������ƁA�Ⴆ�΁A
/// 111 �� 1011 �� 1101 �� 1110 �� 10011 �� 10101 �� �c �� 11100 �� 100011 �� �c 111000 �� 1000011 �� �c (2�i���\��)
/// �ƂȂ�B
/// </return>
/// <example>
/// ���[�v�̃T���v���B���̗�ł�2�i���\���ŁA111�`11100�̑g�ݍ��킹���擾����B�F
/// int n = 5, k = 3;
/// for (int bit = (1 << k) - 1; bit < (1 << n); bit = next_combination(bit)) {
///     // (���炩�̏���)
/// }
/// <code>
/// 
/// </code>
/// </example>
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
