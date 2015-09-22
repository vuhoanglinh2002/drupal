<div>
    <table class="reference" style="width:100%">
        <tbody>
        <tr>
            <td>FULL NAME : <?php print $items->full_name; ?></td>
            <td>EMPLOYEE ID : <?php print $items->employee_id ?></td>
            <td>DOB : <?php print date('d/m/Y', $items->dayofbirth) ?></td>
        </tr>
        </tbody>
    </table>
</div>