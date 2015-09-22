<div>
    <?php if ($items) : ?>
        <table class="reference" style="width:100%">
            <tbody>
            <tr>
                <th>EMPLOYEE ID</th>
                <th>FULL NAME</th>
                <th>DAY OF BIRTH</th>
                <th>EDIT</th>
            </tr>
            <?php foreach ($items as $emp): ?>
                <tr>
                    <td><?php print $emp->employee_id; ?></td>
                    <td><?php print $emp->full_name ?></td>
                    <td><?php print date('Y-m-d', $emp->dayofbirth) ?></td>
                    <td><?php print $emp->gender == 0 ? 'Male' : 'Female'; ?></td>
                    <td><a href="employee/edit/<?php print $emp->id; ?>">Edit</a></td>
                </tr>
            <?php endforeach; ?>
            </tbody>
        </table>
    <?php else: ?>
        <div>Empty list!</div>
    <?php endif; ?>
</div>